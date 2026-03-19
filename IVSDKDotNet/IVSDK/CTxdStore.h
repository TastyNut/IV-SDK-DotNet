struct TxdDef
{
	rage::pgDictionary<rage::grcTexturePC>* m_pDictionary;		// 00-04
	int32_t m_nRefCount;										// 04-08
	uint32_t m_nHash;											// 08-0C
	int32_t m_nParent;											// 0C-10
};
VALIDATE_SIZE(TxdDef, 0x10);

class CTxdStore
{
public:
	// txds are rage::pgDictionary<rage::grcTexture>
	// see 0x487460, loads fonts and buttons
	
	static inline rage::pgDictionary<rage::grcTexturePC>*& ms_pStoredTxd = **(rage::pgDictionary<rage::grcTexturePC>***)AddressSetter::Get("CTxdStore", "ms_pStoredTxd", 1);

	static void AddRef(int slot)
	{
		static void(__cdecl* fn)(int) = injector::GetBranchDestination(AddressSetter::Get("CTxdStore", "AddRef")).get();
		fn(slot);
	}
	static int AddTxdSlot(char* sName)
	{
		static int(__cdecl* fn)(char*) = injector::GetBranchDestination(AddressSetter::Get("CTxdStore", "AddTxdSlot")).get();
		return fn(sName);
	}
	static int FindTxdSlot(uint32_t nHash)
	{
		static int(__cdecl * fn)(uint32_t) = injector::GetBranchDestination(AddressSetter::Get("CTxdStore", "FindTxdSlot")).get();
        return fn(nHash);
	}
	static int FindTxdSlot(char* sName)
	{
		static int(__cdecl* fn)(char*) = injector::GetBranchDestination(AddressSetter::Get("CTxdStore", "FindTxdSlot_2")).get();
        return fn(sName);
	}
	static bool LoadTxd(int slot, char* sName)
	{
		static int(__cdecl* fn)(int, char*) = injector::GetBranchDestination(AddressSetter::Get("CTxdStore", "LoadTxd")).get();
		return fn(slot, sName);
	}
	static void PushCurrentTxd()
	{
		((void(__cdecl*)())(AddressSetter::Get("CTxdStore", "PushCurrentTxd")))();
	}
	static void SetCurrentTxd(int slot)
	{
		((void(__cdecl*)(int))(AddressSetter::Get("CTxdStore", "SetCurrentTxd")))(slot);
	}
	static void PopCurrentTxd()
	{
		((void(__cdecl*)())(AddressSetter::Get("CTxdStore", "PopCurrentTxd")))();
	}
	static CSprite2d GetTexture(char* sName)
	{
		return ((CSprite2d(__stdcall*)(char*))(AddressSetter::Get("CTxdStore", "GetTexture")))(sName);
	}
};