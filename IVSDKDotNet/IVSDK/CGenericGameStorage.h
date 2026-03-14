class CGenericGameStorage
{
public:
	static inline auto ms_ValidSaveName = *(char**)AddressSetter::Get("CGenericGameStorage", "ms_ValidSaveName", 11);

	// returns "SGTA4"
	static const char* GetDefaultPCSaveFileName()
	{
		static const char* (__cdecl* fn)() = injector::GetBranchDestination(AddressSetter::Get("CGenericGameStorage", "GetDefaultPCSaveFileName")).get();
		return fn();
	}
	static void MakeValidSaveName(const char* pString, int SlotNumber)
	{
        // pString shouldn't be const but I'm afraid of breaking something if I remove it I'm just casting it and leaving it as a problem for somene else to deal with
		sprintf((char*)pString, "%s%02d", ms_ValidSaveName, SlotNumber);
	}
	static bool SaveDataToWorkBuffer(void* pData, int32_t SizeOfData)
	{
		return ((bool(__cdecl*)(void*, int32_t))(AddressSetter::Get("CGenericGameStorage", "SaveDataToWorkBuffer")))(pData, SizeOfData);
	}
	static bool LoadDataFromWorkBuffer(void* pData, int32_t SizeOfData)
	{
		return ((bool(__cdecl*)(void*, int32_t))(AddressSetter::Get("CGenericGameStorage", "LoadDataFromWorkBuffer")))(pData, SizeOfData);
	}
};