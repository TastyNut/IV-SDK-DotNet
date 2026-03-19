namespace rage { class fiPackfile; }

class CStreaming
{
public:
	// static inline rage::fiPackfile* m_pPlayerPackfile = AddressSetter::GetRef<rage::fiPackfile*>(0xF503FC, 0xECEBCC); // player:/
	static inline uint32_t& m_nPedModelBudget = **(uint32_t**)AddressSetter::Get("CStreaming", "m_nPedModelBudget");
	static inline uint32_t& m_nVehicleModelBudget = **(uint32_t**)AddressSetter::Get("CStreaming", "m_nVehicleModelBudget");
	static inline uint8_t& ms_disableStreaming = **(uint8_t**)AddressSetter::Get("CStreaming", "ms_disableStreaming", 2);

	static bool IsStreamingDisabled()
	{
		return ms_disableStreaming;
	}

	// this is easier to use until RequestModel is fully documented
	static void ScriptRequestModel(int32_t nHash, uint32_t* pRunningThread = nullptr)
	{
		((void(__cdecl*)(int32_t, uint32_t*))(AddressSetter::Get("CStreaming", "ScriptRequestModel")))(nHash, pRunningThread);
	}
	// todo: this is actually a generic file request function.
	// fileId is the index of the file in the corresponding file/asset store and fileType is returned by 0x63D480 (patch 8)
	static void RequestModel(int32_t fileId, int32_t fileType, int32_t nFlags)
	{
		((void(__cdecl*)(int32_t, int32_t, int32_t))(AddressSetter::Get("CStreaming", "RequestModel")))(fileId, fileType, nFlags);
	}
	static void LoadAllRequestedModels(bool priorityOnly)
	{
		((void(__cdecl*)(bool))(AddressSetter::Get("CStreaming", "LoadAllRequestedModels")))(priorityOnly);
	}
	// images.txt
	static void AddImageList(char* fileName)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get("CStreaming", "AddImageList")))(fileName);
	}

	static rage::fiPackfile* GetPlayerPackfile()
	{
		return ((rage::fiPackfile*(__cdecl*)())(AddressSetter::Get("CStreaming", "GetPlayerPackfile")))();
	}
	static void ClosePlayerPackfile()
	{
		((void(__cdecl*)())(AddressSetter::Get("CStreaming", "ClosePlayerPackfile")))();
	}
};