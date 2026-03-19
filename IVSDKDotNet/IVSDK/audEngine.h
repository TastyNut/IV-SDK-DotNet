class audConfig
{
public:

	void LoadFromFile(char* path)
	{
		((void(__thiscall*)(audConfig*, char*))(AddressSetter::Get("audConfig", "LoadFromFile")))(this, path);
	}
};

class audEngine
{
public:
	static inline audConfig& m_pSoundsConfig = *(audConfig*)(*(uint8_t**)AddressSetter::Get("audEngine", "AudioEngine", 1) + 0x278);
	static inline audConfig& m_pCurvesConfig = *(audConfig*)(*(uint8_t**)AddressSetter::Get("audEngine", "AudioEngine", 1) + 0x64);
	static inline audConfig& m_pGameConfig	 = *(audConfig*)(*(uint8_t**)AddressSetter::Get("audEngine", "AudioEngine", 1) + 0x2D4);

	// this is used after every category patch, but the parameter is 1 in ep2 and 0 in the rest
	void SetUnknown(float unk1)
	{
		((void(__thiscall*)(audEngine*, float))(AddressSetter::Get("audEngine", "SetUnknown")))(this, unk1);
	}
};

audEngine& AudioEngine = **(audEngine**)AddressSetter::Get("audEngine", "AudioEngine", 1);