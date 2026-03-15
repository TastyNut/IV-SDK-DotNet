#include <filesystem>
#include <unordered_map>

#include "injector/injector.hpp"

class AddressSetter
{
public:
	static inline void Init()
	{
		if (m_bInitialized)
			return;

		m_nBaseAddress = (uint32_t)GetModuleHandle(NULL);

		// Dertemine the game version
		DetermineVersion();

		// Load config file according to the game version
		if (!LoadCurrentVersionConfig())
		{
			MessageBoxA(NULL, std::string("Config file for version ").append(std::to_string(m_nCurrentExeVersion)).append(" was not found! IVSDK might not be compatible with this version yet.").c_str(), "IVSDK", MB_ICONERROR);
			exit(1);
			return;
		}

		m_bInitialized = true;
	}

	static inline uint32_t Get(const std::string& section, const std::string& key, uint32_t offset = 0, uint32_t index = 0)
	{
		return GetAddressFromConfig(section, key, offset, index);
	}

	static inline uint32_t GetBaseAddress()
	{
		if (!m_bInitialized)
			Init();

		return m_nBaseAddress;
    }

	static inline uint32_t GetGameVersion()
	{
		if (!m_nCurrentExeVersion)
			m_nCurrentExeVersion = GetVersionFromEXE();

		return m_nCurrentExeVersion;
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
		m_nCurrentExeVersion = GetVersionFromEXE();

		// Set the game version
		plugin::gameVer = (plugin::eGameVersion)m_nCurrentExeVersion;
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
		std::string finalPath = rootPath.append("IVSDK").append(std::to_string(m_nCurrentExeVersion).append(".ini")).string();

		LocalFree(args);

		if(!DoesFileExists(finalPath))
			return false;

		m_pLoadedConfig = new INI<>(finalPath, true);
		return true;
	}


	static inline uint32_t GetAddressFromConfig(const std::string& section, const std::string& key, uint32_t offset = 0, uint32_t index = 0)
	{
		if(!m_bInitialized)
			Init();

		// Get string from section
		std::string str = m_pLoadedConfig->get(section, key, std::string());

		if(str.empty())
		{
			MessageBoxA(NULL, std::string("Address for section ").append(section).append(" and key ").append(key).append(" was not found in the config file for version ").append(std::to_string(m_nCurrentExeVersion)).append("!").c_str(), "IVSDK", MB_ICONERROR);
			exit(1);
			return 0;
		}

		// Get cached address
		if(m_Addresses.find(section + key) != m_Addresses.end())
		{
			return m_Addresses[section + key];
		}
		else if(str.find("0x") == 0 || str.find("0X") == 0)
		{
			// Try convert string to uint32_t
			uint32_t num = static_cast<uint32_t>(std::stoul(str, nullptr, 16));

			return num;
		}
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
				MessageBoxA(NULL, std::string("Pattern for section ").append(section).append(" and key ").append(key).append(" did not match any address in the game.\nGame version: ").append(std::to_string(m_nCurrentExeVersion)).c_str(), "IVSDK", MB_ICONERROR);
				exit(1);
				return 0;
			}

			uint32_t addr = reinterpret_cast<uint32_t>(scan.get(index).get<uint32_t>(offset));
			m_Addresses[section + key] = addr;
			return addr;
		}
		return 0;
	}

private:
	static inline INI<>* m_pLoadedConfig = nullptr;

	static inline std::unordered_map<std::string, uint32_t> m_Addresses;
	static inline uint32_t m_nBaseAddress;
	static inline uint32_t m_nCurrentExeVersion;
	static inline bool m_bInitialized = false;
};