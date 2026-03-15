class CVisibilityPlugins
{
public:
	static inline float& m_pedLodDistanceHigh = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_pedLodDistanceHigh", 2);
	static inline float& m_pedInCarLodDistanceHigh = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_pedInCarLodDistanceHigh", 2);
	static inline float& m_pedLodDistanceMed = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_pedLodDistanceMed", 4);
	static inline float& m_pedLodDistanceLow = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_pedLodDistanceLow", 4);
	static inline float& m_pedLodDistanceVlow = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_pedLodDistanceVlow", 4);
	static inline float& m_pedLodDistanceSlod = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_pedLodDistanceSlod", 4); // all non-mission peds change their modelindex to superlod past this distance
	static inline float& m_carLodDistanceHigh = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_carLodDistanceHigh", 4);
	static inline float& m_carLodDistanceMed = **(float**)AddressSetter::Get("CVisibilityPlugins", "m_carLodDistanceMed", 2);

	static inline char*& sStipplePath = *(char**)AddressSetter::Get("CVisibilityPlugins", "sStipplePath", 1); // platform:/textures
};