#pragma once

#include "Engine/Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Plexity
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define PX_CORE_FATAL(...)		::Plexity::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define PX_CORE_TRACE(...)		::Plexity::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PX_CORE_ERROR(...)		::Plexity::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PX_CORE_WARN(...)		::Plexity::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PX_CORE_INFO(...)		::Plexity::Log::GetCoreLogger()->info(__VA_ARGS__)

#define PX_FATAL(...)			::Plexity::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define PX_TRACE(...)			::Plexity::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PX_ERROR(...)			::Plexity::Log::GetClientLogger()->error(__VA_ARGS__)
#define PX_WARN(...)			::Plexity::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PX_INFO(...)			::Plexity::Log::GetClientLogger()->info(__VA_ARGS__)

