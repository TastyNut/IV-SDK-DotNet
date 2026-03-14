class CCheat
{
public:
	static inline auto& m_bHasPlayerCheated = **(bool**)AddressSetter::Get("CCheat", "m_bHasPlayerCheated", 2);
};