class CGame
{
public:
	static inline char*& sGameFile = *(char**)AddressSetter::Get("CGame", "sGameFile", 1); // common:/data/gta.dat

	static inline uint32_t& m_nCurrentEpisode = **(uint32_t**)AddressSetter::Get("CGame", "m_nCurrentEpisode", 2);
	static inline uint32_t& m_nForcedEpisode = **(uint32_t**)AddressSetter::Get("CGame", "m_nForcedEpisode", 2);
	static inline uint32_t& m_nCurrentEpisodeMenu = **(uint32_t**)AddressSetter::Get("CGame", "m_nCurrentEpisodeMenu", 2); // used for switching hudcolor in each episode's menu screen and for loading the right episode when you hit play
	
	// 1080: 10FC650 (0xCFC650)
	// 1070: 10C7F80 (0xCC7F80)
	static inline uint32_t& m_nMenuState = **(uint32_t**)AddressSetter::Get("CGame", "m_nMenuState", 1);

	static bool Initialise(const char* sGameDat)
	{
		return ((bool(__cdecl*)(const char*))(AddressSetter::Get("CGame", "Initialise")))(sGameDat);
	}

	static bool IsGameRestarting()
	{
		static bool(__cdecl*fn)() = injector::GetBranchDestination(AddressSetter::Get("CGame", "IsGameRestarting")).get();
		return fn();
	}

	static bool SetMenuState(int state)
	{
		m_nMenuState = state;
		return true;
	}

};