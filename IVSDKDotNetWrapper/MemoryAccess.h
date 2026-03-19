#pragma once

namespace IVSDKDotNet 
{
	public ref class MemoryAccess
	{
	public:
		/// <summary>
		/// The base address of GTA IV.
		/// </summary>
		static property uint32_t BaseAddress
		{
			public:		uint32_t get()				{ return m_baseAddress; }
			private:	void set(uint32_t value)	{ m_baseAddress = value; }
		}

		/// <summary>
		/// Gets the current version of GTA IV.
		/// </summary>
		static property eGameVersion GameVersion
		{
			public:		eGameVersion get() { return m_eGameVersion; }
			private:	void set(eGameVersion value) { m_eGameVersion = value; }
		}

	public:
		/// <summary>
		/// Retrieves a memory address from the configuration file of the current game version based on the specified section and key.
		/// </summary>
		/// <param name="section">The name of the section in the configuration file to search.</param>
		/// <param name="key">The key within the specified section whose value is to be retrieved.</param>
		/// <returns>The memory address value associated with the specified section and key inside the configuration file.</returns>
		static uint32_t GetAddressFromConfigFile(String^ section, String^ key);

		static uint32_t ReadMemory(UIntPtr addr, bool vp)
		{
			return injector::ReadMemory<uint32_t>(addr.ToPointer(), vp);
		}

		static void WriteMemory(UIntPtr addr, uint32_t value, bool vp)
		{
			return injector::WriteMemory<uint32_t>(addr.ToPointer(), value, vp);
		}

	internal:
		static void Initialise(uint32_t version, uint32_t baseAddress);

	private:
		static bool m_bGotInitialised;
		static eGameVersion m_eGameVersion;
		static uint32_t m_baseAddress;
	};
}