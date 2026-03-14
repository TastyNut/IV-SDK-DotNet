class CNetwork
{
public:
	static inline void*& m_pClientBroadcastVars = **(void***)AddressSetter::Get("CNetwork", "m_pClientBroadcastVars", 1);
	static inline void*& m_pClientBroadcastVarSize = **(void***)AddressSetter::Get("CNetwork", "m_pClientBroadcastVarSize", 1);
	static inline uint32_t& m_bNetworkSession = **(uint32_t**)AddressSetter::Get("CNetwork", "m_bNetworkSession", 2);
	static inline uint32_t& m_nNetworkStatus = **(uint32_t**)AddressSetter::Get("CNetwork", "m_nNetworkStatus", 1);
	static inline bool& m_bIsHostingGame = **(bool**)AddressSetter::Get("CNetwork", "m_bIsHostingGame", 2);
	static bool IsNetworkGameRunning()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get("CNetwork", "IsNetworkGameRunning")))();
	}
	static bool IsNetworkSession()
	{
		return m_bNetworkSession == 1;
	}
	static void CheckFramerate(bool bUnk, int time)
	{
		((void(__cdecl*)(bool, int))(AddressSetter::Get("CNetwork", "CheckFramerate")))(bUnk, time);
	}
};