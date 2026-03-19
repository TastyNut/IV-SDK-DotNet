class CGameLogic
{
public:
	static inline auto& bPenaltyForDeathApplies = **(bool**)AddressSetter::Get("CGameLogic", "bPenaltyForDeathApplies", 2);
	static inline auto& bPenaltyForArrestApplies = **(bool**)AddressSetter::Get("CGameLogic", "bPenaltyForArrestApplies", 2);

	static bool Save()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get("CGameLogic", "Save")))();
	}
	static bool Load()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get("CGameLogic", "Load")))();
	}
	static void RestorePlayerStuffDuringResurrection(CPed* pPlayerPed, CVector NewCoors, float NewHeading)
	{
		((void(__cdecl*)(CPed*, CVector, float))(AddressSetter::Get("CGameLogic", "RestorePlayerStuffDuringResurrection")))(pPlayerPed, NewCoors, NewHeading);
	}
};