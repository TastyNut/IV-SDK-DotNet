#include "pch.h"
#include "MemoryAccess.h"

namespace IVSDKDotNet
{

	// - - - Methods / Functions - - -
	void MemoryAccess::Initialise(uint32_t version, uint32_t baseAddress)
	{
		if (!m_bGotInitialised)
		{
			GameVersion = (eGameVersion)version;
			BaseAddress = baseAddress;
			m_bGotInitialised = true;
		}
	}

	uint32_t MemoryAccess::GetAddressFromConfigFile(String^ section, String^ key)
	{
		msclr::interop::marshal_context ctx;
		return AddressSetter::Get(ctx.marshal_as<const char*>(section), ctx.marshal_as<const char*>(key));
	}

}