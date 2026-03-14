class CAudioZones
{
public:
	static inline auto& m_NumSpheres = **(uint32_t**)AddressSetter::Get("CAudioZones", "m_NumSpheres", 2);
	static inline auto m_aActiveSpheres = *(int32_t**)AddressSetter::Get("CAudioZones", "m_aActiveSpheres", 3);
	static inline auto& m_NumActiveSpheres = **(uint32_t**)AddressSetter::Get("CAudioZones", "m_NumActiveSpheres", 2);
	static inline auto& m_NumBoxes = **(uint32_t**)AddressSetter::Get("CAudioZones", "m_NumBoxes", 2);
	static inline auto m_aActiveBoxes = *(int32_t**)AddressSetter::Get("CAudioZones", "m_aActiveBoxes", 3);
	static inline auto& m_NumActiveBoxes = **(uint32_t**)AddressSetter::Get("CAudioZones", "m_NumActiveBoxes", 2);

	static void Update(bool bForceUpdate, CVector TestCoors)
	{
		((void(__cdecl*)(bool, CVector))(AddressSetter::Get("CAudioZones", "Update")))(bForceUpdate, TestCoors);
	}
};
auto& LastUpdateCoors = **(CVector**)AddressSetter::Get("CAudioZones", "LastUpdateCoors", 4);