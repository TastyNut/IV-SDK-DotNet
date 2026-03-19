struct IplDef
{
	uint8_t pad[0x60];				// 00-60
};
VALIDATE_SIZE(IplDef, 0x60);

class CIplStore
{
public:
	static inline CQuadTreeNode*& ms_pQuadTree = **(CQuadTreeNode***)AddressSetter::Get("CIplStore", "ms_pQuadTree", 2);
	static inline CPool<IplDef>*& ms_pPool = **(CPool<IplDef>***)AddressSetter::Get("CIplStore", "ms_pPool", 1); // dupe of the one in CPools for convenience

	static inline void LoadIpls(CVector pos, bool unk)
	{
		((void(__cdecl*)(CVector, bool))(AddressSetter::Get("CIplStore", "LoadIpls")))(pos, unk);
	}
	static inline void SetIplsRequired(CVector pos)
	{
		static void(__cdecl* fn)(CVector) = injector::GetBranchDestination((AddressSetter::Get("CIplStore", "SetIplsRequired"))).get();
		fn(pos);
	}
};

inline bool& gbIplsNeededAtPosn = **(bool**)AddressSetter::Get("CIplStore", "gbIplsNeededAtPosn", 2);
inline CVector& gvecIplsNeededAtPosn = **(CVector**)AddressSetter::Get("CIplStore", "gvecIplsNeededAtPosn", 4);

inline void SetIfIplIsRequired(CVector2D* pos, IplDef* def)
{
	((void(__cdecl*)(CVector2D*, IplDef*))(AddressSetter::Get("CIplStore", "SetIfIplIsRequired")))(pos, def);
}

inline void SetIfIplIsRequiredReducedBB(CVector2D* pos, IplDef* def)
{
	((void(__cdecl*)(CVector2D*, IplDef*))(AddressSetter::Get("CIplStore", "SetIfIplIsRequiredReducedBB")))(pos, def);
}