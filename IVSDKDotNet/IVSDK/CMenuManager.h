struct tControlRemapInfo
{
	uint8_t m_nControlId;					// 00-01 see ePadControls
	bool m_bDontShowInMenu;					// 01-02
	uint16_t m_nBoundKey;					// 02-04 display only?
	uint8_t pad[0x4];						// 04-08
	wchar_t m_sControlName[24];				// 08-38
	uint8_t pad2[0x3C];						// 38-74
	wchar_t m_sAltControlName[24];			// 74-A4
	uint8_t pad3[0x3E];						// A4-E2
};
VALIDATE_SIZE(tControlRemapInfo, 0xE2);
VALIDATE_OFFSET(tControlRemapInfo, m_nControlId, 0x0);
VALIDATE_OFFSET(tControlRemapInfo, m_sControlName, 0x8);
VALIDATE_OFFSET(tControlRemapInfo, m_sAltControlName, 0x74);

class CMenuManager
{
public:
	static inline uint32_t& m_bInvertMouseX = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_bInvertMouseX", 13);
	static inline uint32_t& m_bInvertRightStickX = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_bInvertRightStickX", 10);
	static inline uint32_t& m_bAutoSave = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_bAutoSave", 13);
	static inline uint32_t& m_bClipCapture = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_bClipCapture", 2);
	static inline uint32_t& m_bHeliMouseControls = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_bHeliMouseControls", 13);
	static inline uint32_t& m_bHudOn = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_bHudOn", 13);
	static inline uint32_t& m_nRadarMode = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_nRadarMode", 13);

	static inline uint32_t& m_nMouseSensitivity = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_nMouseSensitivity", 13);

	// written to float values when changed in menu
	static inline uint32_t& m_nBrightness = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_nBrightness", 13);
	static inline uint32_t& m_nContrast = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_nContrast", 13);
	static inline uint32_t& m_nSaturation = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_nSaturation", 13);

	static inline uint32_t& m_nVehicleDensity = **(uint32_t**)AddressSetter::Get("CMenuManager", "m_nVehicleDensity", 1);

	static inline float& m_fBrightness = **(float**)AddressSetter::Get("CMenuManager", "m_fBrightness", 4);
	static inline float& m_fContrast = **(float**)AddressSetter::Get("CMenuManager", "m_fContrast", 4);
	static inline float& m_fSaturation = **(float**)AddressSetter::Get("CMenuManager", "m_fSaturation", 4);

	static inline tControlRemapInfo* m_aRemapOptions = *(tControlRemapInfo**)AddressSetter::Get("CMenuManager", "m_aRemapOptions", 3);
};