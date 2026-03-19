class CGameConfigReader
{
public:
	void LoadFile(char* fileName)
	{
		((void(__thiscall*)(CGameConfigReader*, char*))(AddressSetter::Get("CGameConfigReader", "LoadFile")))(this, fileName);
	}
};
CGameConfigReader*& GameConfigReader = *(CGameConfigReader**)AddressSetter::Get("CGameConfigReader", "GameConfigReader", 2);