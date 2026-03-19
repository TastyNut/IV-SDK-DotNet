class CRestart
{
public:
	static inline auto& NumberOfHospitalRestarts = **(uint32_t**)AddressSetter::Get("CRestart", "NumberOfHospitalRestarts");
	static inline auto& NumberOfPoliceRestarts = **(uint32_t**)AddressSetter::Get("CRestart", "NumberOfPoliceRestarts");
	static inline auto& NumberOfSafehouses = **(uint32_t**)AddressSetter::Get("CRestart", "NumberOfSafehouses");

	static inline auto HospitalRestartPoints = *(CVector_pad**)AddressSetter::Get("CRestart", "HospitalRestartPoints");
	static inline auto HospitalRestartHeadings = *(float**)AddressSetter::Get("CRestart", "HospitalRestartHeadings");
	static inline auto HospitalRestartWhenToUse = *(int**)AddressSetter::Get("CRestart", "HospitalRestartWhenToUse");

	static inline auto PoliceRestartPoints = **(CVector_pad**)AddressSetter::Get("CRestart", "PoliceRestartPoints");
	static inline auto PoliceRestartHeadings = **(float**)AddressSetter::Get("CRestart", "PoliceRestartHeadings");
	static inline auto PoliceRestartWhenToUse = **(int**)AddressSetter::Get("CRestart", "PoliceRestartWhenToUse");

	struct tSafehouse
	{
		CVector_pad vPos;							// 00-10
		float fHeading;								// 10-14
		char sName[32];								// 14-34
		uint32_t nWhenToUse;						// 34-38
		uint8_t bEnabled;							// 38-39
		uint8_t pad[0x7];							// 39-40
	};
	VALIDATE_SIZE(tSafehouse, 0x40);

	static inline auto Safehouses = (tSafehouse*)(*(uint8_t**)AddressSetter::Get("CRestart", "Safehouses") - 0x10);

	static inline auto& bOverrideRestart = **(bool**)AddressSetter::Get("CRestart", "bOverrideRestart");
	static inline auto& OverridePosition = **(CVector_pad**)AddressSetter::Get("CRestart", "OverridePosition");
	static inline auto& OverrideHeading = **(float**)AddressSetter::Get("CRestart", "OverrideHeading");
	static inline auto& bFadeInAfterNextDeath = **(bool**)AddressSetter::Get("CRestart", "bFadeInAfterNextDeath");
	static inline auto& ExtraHospitalRestartCoors = **(CVector_pad**)AddressSetter::Get("CRestart", "ExtraHospitalRestartCoors");
	static inline auto& ExtraHospitalRestartHeading = **(float**)AddressSetter::Get("CRestart", "ExtraHospitalRestartHeading");
	static inline auto& ExtraHospitalRestartWhenToUse = **(uint32_t**)AddressSetter::Get("CRestart", "ExtraHospitalRestartWhenToUse");
	static inline auto& ExtraPoliceStationRestartCoors = **(CVector_pad**)AddressSetter::Get("CRestart", "ExtraPoliceStationRestartCoors");
	static inline auto& ExtraPoliceStationRestartHeading = **(float**)AddressSetter::Get("CRestart", "ExtraPoliceStationRestartHeading");
	static inline auto& ExtraPoliceStationRestartWhenToUse = **(uint32_t**)AddressSetter::Get("CRestart", "ExtraPoliceStationRestartWhenToUse", 3);

	static bool Save()
	{
		static int(__cdecl* fn)() = injector::GetBranchDestination(AddressSetter::Get("CRestart", "Save")).get();
		return fn();
	}
	static bool Load()
	{
		static int(__cdecl * fn)() = injector::GetBranchDestination(AddressSetter::Get("CRestart", "Load")).get();
		return fn();
	}
};