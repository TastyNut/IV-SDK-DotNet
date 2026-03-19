class CCutsceneMgr
{
public:
	static inline uint32_t& ms_running = **(uint32_t**)AddressSetter::Get("CCutsceneMgr", "ms_running", 2);

	static bool IsRunning()
	{
		return ms_running != 0;
	}
};