class CTimer
{
public:
	static inline uint8_t& m_CodePause = **(uint8_t**)AddressSetter::Get("CTimer", "m_CodePause", 3);
	static inline uint8_t& m_UserPause = **(uint8_t**)AddressSetter::Get("CTimer", "m_UserPause", 3);
	static inline uint32_t& m_FrameCounter = **(uint32_t**)AddressSetter::Get("CTimer", "m_FrameCounter", 2);
	static inline uint32_t& m_snTimeInMilliseconds = **(uint32_t**)AddressSetter::Get("CTimer", "m_snTimeInMilliseconds", 2);
	static inline uint32_t& m_sTimerLength = **(uint32_t**)AddressSetter::Get("CTimer", "m_sTimerLength", 2);
	static inline float& ms_fMinTimeStep = **(float**)AddressSetter::Get("CTimer", "ms_fMinTimeStep", 4);
	static inline float& ms_fMaxTimeStep = **(float**)AddressSetter::Get("CTimer", "ms_fMaxTimeStep", 4);
	static inline float& ms_fTimeStep = **(float**)AddressSetter::Get("CTimer", "ms_fTimeStep", 4);
	static inline float& ms_fTimeStepNonClipped = **(float**)AddressSetter::Get("CTimer", "ms_fTimeStepNonClipped", 4);
	static inline float& ms_fTimeScale = **(float**)AddressSetter::Get("CTimer", "ms_fTimeScale", 3); // set by scripts
	static inline float& ms_fTimeScale2 = **(float**)AddressSetter::Get("CTimer", "ms_fTimeScale2", 4); // set by scripts
	static inline float& ms_fTimeScale3 = **(float**)AddressSetter::Get("CTimer", "ms_fTimeScale3", 4); // changes for death camera

	static bool GetIsPaused()
	{
		static uint32_t(__cdecl* fn)() = injector::GetBranchDestination(AddressSetter::Get("CTimer", "GetIsPaused")).get();
		return fn();
	}
};