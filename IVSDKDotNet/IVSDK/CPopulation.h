class CPopulation
{
public:
	static inline auto& ms_nNumCop = **(int32_t**)AddressSetter::Get("CPopulation", "ms_nNumCop", 2);
	static inline auto& ms_nNumEmergency = **(int32_t**)AddressSetter::Get("CPopulation", "ms_nNumEmergency", 2);
	static inline auto& m_AllRandomPedsThisType = **(int32_t**)AddressSetter::Get("CPopulation", "m_AllRandomPedsThisType", 2);
	static inline auto& PedDensityMultiplier = **(float**)AddressSetter::Get("CPopulation", "PedDensityMultiplier", 4);
	
	static inline auto& ScenarioPedDensityMultiplier = **(float**)AddressSetter::Get("CPopulation", "ScenarioPedDensityMultiplier", 4);
	static inline auto& ScenarioPedDensityMultiplier2 = *(*(float**)AddressSetter::Get("CPopulation", "ScenarioPedDensityMultiplier", 4) + 1);

	static void Initialise()
	{
		return ((void(__cdecl*)())(AddressSetter::Get("CPopulation", "Initialise")))();
	}
	static void RemovePed(CPed* pPed, bool unk)
	{
		return ((void(__cdecl*)(CPed*, bool))(AddressSetter::Get("CPopulation", "RemovePed")))(pPed, unk);
	}
};