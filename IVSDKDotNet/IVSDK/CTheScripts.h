#pragma unmanaged

struct building_swap_struct
{
	CBuilding* pBuilding;
	uint32_t NewModelIndex;
	uint32_t OldModelIndex;
};

class CTheScripts
{
public:
	static inline auto BuildingSwapArray = *(building_swap_struct**)AddressSetter::Get("CTheScripts", "BuildingSwapArray", 3); // BuildingSwapArray[25]

	static inline auto& m_aGlobalVariables = **(uint32_t***)AddressSetter::Get("CTheScripts", "m_aGlobalVariables", 2); // m_aGlobalVariables[65535]?
	static inline auto& m_pCurrentThread = **(uint32_t**)AddressSetter::Get("CTheScripts", "m_pCurrentThread", 1);

	static uint32_t FindNativeAddress(uint32_t nativeHash)
	{
		static void* funcPtr = injector::GetBranchDestination(AddressSetter::Get("CTheScripts", "FindNativeAddress")).get();
		
		uint32_t nativePtr;
		_asm
		{
			push esi
			mov esi, nativeHash
			call funcPtr
			pop esi
			mov nativePtr, eax
		}

		return nativePtr;

		//__try
		//{

		//}
		//__except (EXCEPTION_EXECUTE_HANDLER)
		//{
		//	return 0;
		//}
	}

	static int RegisterNativeNoChecks(uint32_t hash, LPVOID funcPtr)
	{
		static int(__stdcall* fn)(uint32_t, LPVOID) = injector::GetBranchDestination(AddressSetter::Get("CTheScripts", "RegisterNativeNoChecks")).get();
		return fn(hash, funcPtr);
	}
	static int RegisterNative(uint32_t hash, LPVOID funcPtr)
	{
		return ((int(__cdecl*)(uint32_t, LPVOID))(AddressSetter::Get("CTheScripts", "RegisterNative")))(hash, funcPtr);
	}

	static const char* GetNameOfCurrentScript()
	{
		static const char* (__cdecl* fn)() = injector::GetBranchDestination(AddressSetter::Get("CTheScripts", "GetNameOfCurrentScript")).get();
		return fn();
	}

	static bool IsPlayerOnAMission()
	{
		static bool(__cdecl* fn)() = injector::GetBranchDestination(AddressSetter::Get("CTheScripts", "IsPlayerOnAMission")).get();
		return fn();
	}
	static void GivePedScriptedTask(int handle, CTask* task, int unk)
	{
		((void(__cdecl*)(int, CTask*, int))(AddressSetter::Get("CTheScripts", "GivePedScriptedTask")))(handle, task, unk);
	}
	static void AddToBuildingSwapArray(CBuilding* pBildng, int32_t OldModIndx, int32_t NewModIndx)
	{
		((void(__cdecl*)(CBuilding*, int32_t, int32_t))(AddressSetter::Get("CTheScripts", "AddToBuildingSwapArray")))(pBildng, OldModIndx, NewModIndx);
	}
	static void UndoBuildingSwaps()
	{
		return ((void(__cdecl*)())(AddressSetter::Get("CTheScripts", "UndoBuildingSwaps")))();
	}
	static void Save()
	{
		return ((void(__cdecl*)())(AddressSetter::Get("CTheScripts", "Save")))();
	}
	static void Load()
	{
		return ((void(__cdecl*)())(AddressSetter::Get("CTheScripts", "Load")))();
	}
};

#pragma managed