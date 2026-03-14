class CReplay
{
public:
	static inline auto& Mode = **(uint32_t**)AddressSetter::Get("CReplay", "Mode", 2);
};