#include "pch.h"
#include "Patterns.h"

namespace IVSDKDotNet
{
	namespace Hooking
	{

		// - - - Methods / Functions - - -
		UIntPtr Patterns::GetAddress(String^ pattern, uint32_t index, uint32_t offset)
		{
			if (String::IsNullOrWhiteSpace(pattern))
				return UIntPtr::Zero;

			msclr::interop::marshal_context ctx;

			auto scan = hook::pattern(std::string_view(ctx.marshal_as<const char*>(pattern), pattern->Length));

			return UIntPtr(scan.get(index).get<uint32_t>(offset));
		}

	}
}