class CPed;
class CVehicle;
class CBuilding;
class CObject;
class CCam;
class CTask;
class CInteriorInst;
class CVehicleStructure;
class CPedMoveBlendOnFoot;
class CDummyPed;
class CDummyTask;
class tPedData;
class CPedIntelligenceNY;
class CAnimBlender;
class fragInstNMGta;
class CPedDataNY;
class CTxdFile;
struct TxdDef;
struct IplDef;
class CQuadTreeNode;
class CPedTargetting;

class CScriptStore;

class CPools
{
public:
	static inline auto& ms_pPedPool = **(CPool<CPed>***)AddressSetter::Get("CPools", "ms_pPedPool", 1);
	static inline auto& ms_pVehiclePool = **(CPool<CVehicle>***)AddressSetter::Get("CPools", "ms_pVehiclePool", 2);
	static inline auto& ms_pBuildingPool = **(CPool<CBuilding>***)AddressSetter::Get("CPools", "ms_pBuildingPool", 2);
	static inline auto& ms_pObjectPool = **(CPool<CObject>***)AddressSetter::Get("CPools", "ms_pObjectPool", 2);
	static inline auto& ms_pCameraPool = **(CPool<CCam>***)AddressSetter::Get("CPools", "ms_pCameraPool", 2);
	static inline auto& ms_pTaskPool = **(CPool<CTask>***)AddressSetter::Get("CPools", "ms_pTaskPool", 2);
	static inline auto& ms_pInteriorInstPool = **(CPool<CInteriorInst>***)AddressSetter::Get("CPools", "ms_pInteriorInstPool", 2);
	static inline auto& ms_pVehicleStructPool = **(CPool<CVehicleStructure>***)AddressSetter::Get("CPools", "ms_pVehicleStructPool", 2);
	static inline auto& ms_pPedMoveBlendPool = **(CPool<CPedMoveBlendOnFoot>***)AddressSetter::Get("CPools", "ms_pPedMoveBlendPool", 2);
	static inline auto& ms_pDummyPedPool = **(CPool<CDummyPed>***)AddressSetter::Get("CPools", "ms_pDummyPedPool", 1);
	static inline auto& ms_pDummyTaskPool = **(CPool<CDummyTask>***)AddressSetter::Get("CPools", "ms_pDummyTaskPool", 2);
	static inline auto& ms_pUnkPedDataPool = **(CPool<tPedData>***)AddressSetter::Get("CPools", "ms_pUnkPedDataPool", 2);
	static inline auto& ms_pPedIntelligencePool = **(CPool<CPedIntelligenceNY>***)AddressSetter::Get("CPools", "ms_pPedIntelligencePool", 2);
	static inline auto& ms_pAnimBlenderPool = **(CPool<CAnimBlender>***)AddressSetter::Get("CPools", "ms_pAnimBlenderPool", 2);
	static inline auto& ms_pFragInstNMGtaPool = **(CPool<fragInstNMGta>***)AddressSetter::Get("CPools", "ms_pFragInstNMGtaPool", 2);
	static inline auto& ms_pPedDataPool = **(CPool<CPedDataNY>***)AddressSetter::Get("CPools", "ms_pPedDataPool", 25);
	static inline auto& ms_pQuadTreeNodePool = **(CPool<CQuadTreeNode>***)AddressSetter::Get("CPools", "ms_pQuadTreeNodePool", 2);
	static inline auto& ms_pTxdPool = **(CPool<TxdDef>***)AddressSetter::Get("CPools", "ms_pTxdPool", 2);
	static inline auto& ms_pIplPool = **(CPool<IplDef>***)AddressSetter::Get("CPools", "ms_pIplPool", 2);
	static inline auto& ms_pPedTargettingPool = **(CPool<CPedTargetting>***)AddressSetter::Get("CPools", "ms_pPedTargettingPool", 1);

	static inline auto& ms_pScriptStorePool = **(CPool<CScriptStore>***)AddressSetter::Get("CPools", "ms_pScriptStorePool", 2);
};