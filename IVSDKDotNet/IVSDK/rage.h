// any non-class rage functions should go here
namespace rage
{
	static HWND& g_pHWND = **(HWND**)AddressSetter::Get("rage", "g_pHWND", 1);
	static IDirect3DDevice9*& g_pDirect3DDevice = **(IDirect3DDevice9***)AddressSetter::Get("rage", "g_pDirect3DDevice", 2);
	static uint32_t atStringHash(const char* sString, uint32_t* nExistingHash = nullptr)
	{
		return ((uint32_t(__cdecl*)(const char*, uint32_t*))(AddressSetter::Get("rage", "atStringHash")))(sString, nExistingHash);
	}

}