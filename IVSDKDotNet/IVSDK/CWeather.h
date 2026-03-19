class CWeather
{
public:
	static inline auto& ForcedWeatherType = **(int32_t**)AddressSetter::Get("CWeather", "ForcedWeatherType", 2);
	static inline auto& OldWeatherType = **(int32_t**)AddressSetter::Get("CWeather", "OldWeatherType", 2);
	static inline auto& NewWeatherType = **(int32_t**)AddressSetter::Get("CWeather", "NewWeatherType", 2);
	static inline auto& InterpolationValue = **(float**)AddressSetter::Get("CWeather", "InterpolationValue", 4);
	static inline auto& WeatherTypeInList = **(int32_t**)AddressSetter::Get("CWeather", "WeatherTypeInList", 1);
	static inline auto& Rain = **(float**)AddressSetter::Get("CWeather", "Rain", 4);
	static inline auto& ForcedWind = **(float**)AddressSetter::Get("CWeather", "ForcedWind", 4);

	static void ForceWeatherNow(int Type)
	{
		return ((void(__cdecl*)(int))(AddressSetter::Get("CWeather", "ForceWeatherNow")))(Type);
	}
};