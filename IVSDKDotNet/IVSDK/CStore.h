template<typename T>
class CStore
{
public:
	uint32_t m_maxItems;				// 00-04
	uint32_t m_nextItem;				// 04-08
	T* m_storeArray;					// 08-0C
};

auto& ms_vehicleModelStore = **(CStore<CVehicleModelInfo>**)AddressSetter::Get("CStore", "ms_vehicleModelStore");
auto& ms_pedModelStore = **(CStore<CPedModelInfo>**)AddressSetter::Get("CStore", "ms_pedModelStore");