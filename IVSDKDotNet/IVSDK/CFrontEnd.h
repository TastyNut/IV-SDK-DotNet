class CFrontEnd
{
public:
	static inline auto& g_iUserWaypointID = **(int32_t**)AddressSetter::Get("CFrontEnd", "g_iUserWaypointID", 2);
	static inline auto& vMapCursor = **(CVector2D**)AddressSetter::Get("CFrontEnd", "vMapCursor", 2);

	static void SwitchOnWaypoint(int unk_8, float x, float y, bool snapToHoveringBlip, CVector* outPos)
	{
		return ((void(__cdecl*)(int, float, float, bool, CVector*))(AddressSetter::Get("CFrontEnd", "SwitchOnWaypoint")))(unk_8, x, y, snapToHoveringBlip, outPos);
	}
	static void SwitchOffWaypoint()
	{
		return ((void(__cdecl*)())(AddressSetter::Get("CFrontEnd", "SwitchOffWaypoint")))();
	}
	static void ToggleWaypoint()
	{
		return ((void(__cdecl*)())(AddressSetter::Get("CFrontEnd", "ToggleWaypoint")))();
	}
};