#include <filesystem>
#include <unordered_map>

#include "injector/injector.hpp"

class AddressSetter
{
public:
	static inline void Init()
	{
		if (ms_bInitialized)
			return;

		ms_nBaseAddress = (uint32_t)GetModuleHandle(NULL);

		DetermineVersion();

		if (!LoadCurrentVersionConfig())
		{
			MessageBoxA(NULL, std::string("Config file was not found! Please copy the \"IVSDK\" folder in the zip archive you downloaded to your game's root directory.").c_str(), "IVSDK", MB_ICONERROR);
			exit(1);
			return;
		}

		ms_bInitialized = true;

        // this sucks but I can't think of a better way to do it
		// it needs to be done outside dllmain and this is the function that's most likely to be called first after injection
		if(!ms_pPreInitGameOrig)
			ms_pPreInitGameOrig = injector::MakeCALL(Get("Hooks", "PreInitGame"), PreInitGameHook).get();
	}

	static inline uint32_t Get(const std::string& section, const std::string& key, uint32_t offset = 0, uint32_t index = 0)
	{
		return GetAddressFromConfig(section, key, offset, index);
	}

	static inline uint32_t GetBaseAddress()
	{
		if (!ms_bInitialized)
			Init();

		return ms_nBaseAddress;
	}

	static inline uint32_t GetGameVersion()
	{
		if (!ms_nCurrentExeVersion)
			ms_nCurrentExeVersion = GetVersionFromEXE();

		return ms_nCurrentExeVersion;
	}

private:
	static inline bool DoesFileExists(const std::string& name)
	{
		std::ifstream f(name.c_str());
		return f.good();
	}

	static inline uint32_t GetVersionFromEXE()
	{
		TCHAR szFileName[MAX_PATH];

		GetModuleFileName(NULL, szFileName, MAX_PATH);

		DWORD  verHandle = 0;
		UINT   size = 0;
		LPBYTE lpBuffer = NULL;
		DWORD  verSize = GetFileVersionInfoSize(szFileName, &verHandle);

		if(verSize != NULL)
		{
			LPSTR verData = new char[verSize];

			if(GetFileVersionInfo(szFileName, verHandle, verSize, verData))
			{
				if(VerQueryValue(verData, TEXT("\\"), (VOID FAR * FAR*) & lpBuffer, &size))
				{
					if(size)
					{
						VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
						if(verInfo->dwSignature == 0xfeef04bd)
						{
							std::string str = std::to_string((verInfo->dwFileVersionMS >> 16) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionMS >> 0) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionLS >> 16) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionLS >> 0) & 0xffff);
							delete[] verData;
							return std::stoi(str);
						}
					}
				}
			}
			delete[] verData;
		}
		return 0;
	}

	static inline void DetermineVersion()
	{
		// Determine the game version
		ms_nCurrentExeVersion = GetVersionFromEXE();

		// Set the game version
		plugin::gameVer = (plugin::eGameVersion)ms_nCurrentExeVersion;
	}

	static inline bool LoadCurrentVersionConfig()
	{
		int numArgs;
		LPWSTR* args = CommandLineToArgvW(GetCommandLineW(), &numArgs);

		if(args == NULL)
		{
			MessageBoxA(NULL, "Failed to parse command line of current process!", "IVSDK", MB_ICONERROR);
			exit(1);
			return false;
		}

		std::filesystem::path rootPath = std::filesystem::path(std::wstring(args[0])).remove_filename();
		std::string versionPath = rootPath.append("IVSDK").append(std::to_string(ms_nCurrentExeVersion).append(".ini")).string();
		std::string patternsPath = rootPath.replace_filename("Patterns.ini").string();
		ms_Addresses.ConfigPath = versionPath;

		LocalFree(args);

		if (!DoesFileExists(versionPath) && !DoesFileExists(patternsPath))
		{
			return false;
		}

		ms_pLoadedConfig[0] = new INI<>(versionPath, true);
		ms_pLoadedConfig[1] = new INI<>(patternsPath, true);

		return true;
	}


	static inline uint32_t GetAddressFromConfig(const std::string& section, const std::string& key, uint32_t offset = 0, uint32_t index = 0)
	{
		if(!ms_bInitialized)
			Init();

		// Get string from section
		std::string str = ms_pLoadedConfig[0]->get(section, key, std::string());
		if(str.empty())
		{
            str = ms_pLoadedConfig[1]->get(section, key, std::string());
			if(str.empty())
			{
				MessageBoxA(NULL, std::string("Address for section ").append(section).append(" and key ").append(key).append(" was not found in the config file for version ").append(std::to_string(ms_nCurrentExeVersion)).append("!").c_str(), "IVSDK", MB_ICONERROR);
				exit(1);
				return 0;
			}
		}

		// Get cached address
		auto mapKey = AddressMapKey{section, key};
		if(ms_Addresses.Map.find(mapKey) != ms_Addresses.Map.end())
		{
			return ms_nBaseAddress + ms_Addresses.Map[mapKey];
		}
		// Get relative offset
		else if(str.find("0x") == 0 || str.find("0X") == 0)
		{
			uint32_t relAddr = static_cast<uint32_t>(std::stoul(str, nullptr, 16));
			return ms_nBaseAddress + relAddr;
		}
		// Get pattern(s)
		else
		{
			hook::pattern scan;
			if(str.find(",") != str.npos)
			{
				std::stringstream ss{str};
				while(std::getline(ss, str, ','))
				{
					auto start = str.find_first_not_of(" \t");
					auto end = str.find_last_not_of(" \t");
					if(start != std::string::npos)
					{
						std::string patternStr = str.substr(start, end - start + 1);
						scan = hook::pattern(str);
						if(!scan.empty())
							break;
					}
				}
			}
			else
			{
				scan = hook::pattern(str);
			}

			if(scan.empty())
			{
				MessageBoxA(NULL, std::string("Pattern for section ").append(section).append(" and key ").append(key).append(" did not match any address in the game.\nGame version: ").append(std::to_string(ms_nCurrentExeVersion)).c_str(), "IVSDK", MB_ICONERROR);
				exit(1);
				return 0;
			}

			uint32_t addr = reinterpret_cast<uint32_t>(scan.get(index).get<uint32_t>(offset));
			ms_Addresses.Map[mapKey] = addr - ms_nBaseAddress;
			return addr;
		}
		return 0;
	}

	// Block game initialization until the plugin is initialized
	static inline void(*ms_pPreInitGameOrig)();
	static void PreInitGameHook()
	{
		WaitForSingleObject(plugin::hInitializationDone, INFINITE);
		ms_pPreInitGameOrig();
	}

private:
	struct AddressMapKey
	{
		std::string Section;
		std::string Key;

		bool operator==(const AddressMapKey& rhs) const
		{
			return Section == rhs.Section && Key == rhs.Key;
		}
	};

	struct AddressMapKeyHasher
	{
		std::size_t operator()(const AddressMapKey& key) const
		{
			std::size_t a = std::hash<std::string>{}(key.Section);
			std::size_t b = std::hash<std::string>{}(key.Key);

			return a ^ (b << 1);
		}
	};

	// Wrapper whose sole purpose is calling a custom destructor when the game exits to save the cached addresses
	struct MapWrapper
	{
		MapWrapper() = default;

		~MapWrapper()
		{
			std::vector<std::pair<AddressMapKey, uint32_t>> sortedMap{Map.begin(), Map.end()};
			std::sort(sortedMap.begin(), sortedMap.end(), [](const auto& a, const auto& b)
			{
				return a.first.Section < b.first.Section;
			});

			std::ofstream oFile(ConfigPath);
			oFile << "; This is an auto-generated file. Do not edit it.\n";
			std::string lastSection;
			for(const auto& pair : sortedMap)
			{
				if(lastSection != pair.first.Section)
				{
                    lastSection = pair.first.Section;
					oFile << "[" << pair.first.Section << "]\n";
				}
				oFile << pair.first.Key << "=0x" << std::hex << pair.second << '\n';
			}
		}

		std::unordered_map<AddressMapKey, uint32_t, AddressMapKeyHasher> Map;
		std::string ConfigPath;
	};

	// For current version and fallback
	static inline INI<>* ms_pLoadedConfig[2] = {nullptr, nullptr};

	static inline MapWrapper ms_Addresses;
	static inline uint32_t ms_nBaseAddress;
	static inline uint32_t ms_nCurrentExeVersion;
	static inline bool ms_bInitialized = false;
};