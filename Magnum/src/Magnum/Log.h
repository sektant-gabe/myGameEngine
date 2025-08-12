#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Magnum {

	class MAGNUM_API Log
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

// Core log macros
#define MAGNUM_CORE_TRACE(...)  ::Magnum::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MAGNUM_CORE_INFO(...)   ::Magnum::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MAGNUM_CORE_WARN(...)   ::Magnum::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MAGNUM_CORE_ERROR(...)  ::Magnum::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MAGNUM_CORE_FATAL(...)  ::Magnum::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros

#define MAGNUM_TRACE(...)       ::Magnum::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MAGNUM_INFO(...)        ::Magnum::Log::GetClientLogger()->info(__VA_ARGS__)
#define MAGNUM_WARN(...)        ::Magnum::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MAGNUM_ERROR(...)       ::Magnum::Log::GetClientLogger()->error(__VA_ARGS__)
#define MAGNUM_FATAL(...)       ::Magnum::Log::GetClientLogger()->fatal(__VA_ARGS__)

