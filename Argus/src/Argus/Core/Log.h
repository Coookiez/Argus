#pragma once

#include "Argus/Core/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

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

// Core log macros
#define AS_CORE_TRACE(...)		::Argus::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define AS_CORE_INFO(...)		::Argus::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define AS_CORE_WARN(...)		::Argus::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define AS_CORE_ERROR(...)		::Argus::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define AS_CORE_FATAL(...)		::Argus::Log::GetCoreLogger()->fatal(__VA_ARGS__) 

// Client log macros
#define AS_TRACE(...)			::Argus::Log::GetClientLogger()->trace(__VA_ARGS__) 
#define AS_INFO(...)			::Argus::Log::GetClientLogger()->info(__VA_ARGS__) 
#define AS_WARN(...)			::Argus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AS_ERROR(...)			::Argus::Log::GetClientLogger()->error(__VA_ARGS__)
#define AS_FATAL(...)			::Argus::Log::GetClientLogger()->fatal(__VA_ARGS__)