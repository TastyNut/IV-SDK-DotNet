class CClock
{
public:
	static inline uint32_t& ms_nGameClockForcedMinutes = **(uint32_t**)AddressSetter::Get("CClock", "ms_nGameClockForcedMinutes", 5);
	static inline uint32_t& ms_nGameClockForcedHours = **(uint32_t**)AddressSetter::Get("CClock", "ms_nGameClockForcedHours", 7);
	static inline uint32_t& CurrentDay = **(uint32_t**)AddressSetter::Get("CClock", "CurrentDay", 2);
	static inline uint32_t& ms_nGameClockSeconds = **(uint32_t**)AddressSetter::Get("CClock", "ms_nGameClockSeconds", 1);
	static inline uint32_t& ms_nGameClockMinutes = **(uint32_t**)AddressSetter::Get("CClock", "ms_nGameClockMinutes", 5);
	static inline uint32_t& ms_nGameClockHours = **(uint32_t**)AddressSetter::Get("CClock", "ms_nGameClockHours", 2);
	static inline uint32_t& ms_nGameClockDays = **(uint32_t**)AddressSetter::Get("CClock", "ms_nGameClockDays", 1);
	static inline uint32_t& ms_nGameClockMonth = **(uint32_t**)AddressSetter::Get("CClock", "ms_nGameClockMonth", 2);
	static inline uint32_t& ms_nMillisecondsPerGameMinute = **(uint32_t**)AddressSetter::Get("CClock", "ms_nMillisecondsPerGameMinute", 2);
};