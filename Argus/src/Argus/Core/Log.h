#pragma once

#include "glm/gtx/string_cast.hpp"

#include "Argus/Core/Base.h"
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace Argus {
	
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternio)
{
	return os << glm::to_string(quaternio);
}

// Core log macros
#define AS_CORE_TRACE(...)		::Argus::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define AS_CORE_INFO(...)		::Argus::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define AS_CORE_WARN(...)		::Argus::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define AS_CORE_ERROR(...)		::Argus::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define AS_CORE_CRITICAL(...)	::Argus::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define AS_TRACE(...)			::Argus::Log::GetClientLogger()->trace(__VA_ARGS__) 
#define AS_INFO(...)			::Argus::Log::GetClientLogger()->info(__VA_ARGS__) 
#define AS_WARN(...)			::Argus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AS_ERROR(...)			::Argus::Log::GetClientLogger()->error(__VA_ARGS__)
#define AS_CRITICAL(...)		::Argus::Log::GetClientLogger()->critical(__VA_ARGS__)