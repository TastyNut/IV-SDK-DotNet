#include "pch.h"
#include "IVMenuManager.h"

namespace IVSDKDotNet
{
	static uint32_t s_pSettings = *(uint32_t*)AddressSetter::Get("CMenuManager", "m_bInvertMouseX", 13);

	// - - - Methods / Functions - - -
	uint32_t IVMenuManager::GetSetting(eSettings setting)
	{
		return *(uint32_t*)(s_pSettings + (uint32_t)setting);
	}
	void IVMenuManager::SetSetting(eSettings setting, uint32_t value)
	{
		injector::WriteMemory(s_pSettings + (uint32_t)setting, value, true);
	}
}