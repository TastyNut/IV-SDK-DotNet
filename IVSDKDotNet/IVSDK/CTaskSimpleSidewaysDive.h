class CTaskSimpleSidewaysDive : public CTaskSimple
{
public:
	CTaskSimpleSidewaysDive(bool bDirection)
	{
		static void(__thiscall* fn)(CTaskSimpleSidewaysDive*, bool) = injector::GetBranchDestination(AddressSetter::Get("CTaskSimpleSidewaysDive", "CTaskSimpleSidewaysDive")).get();
        fn(this, bDirection);
	}
};