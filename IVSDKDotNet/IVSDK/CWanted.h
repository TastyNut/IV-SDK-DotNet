class CWanted
{
public:
	static inline auto& MaximumWantedLevel = **(uint32_t**)AddressSetter::Get("CWanted", "MaximumWantedLevel", 2);
	static inline auto& nMaximumWantedLevel = **(uint32_t**)AddressSetter::Get("CWanted", "nMaximumWantedLevel", 2);
};