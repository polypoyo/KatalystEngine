#pragma once

#include <KatalystPCH.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

#include "Core/Core.h"
namespace Katalyst
{
	class KL_API Log 
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

// This is an defintion to use the spdlog's  text formatter 
#define KL_TEXT_FORMATTER(fmt_str, ...) spdlog::info(fmt_str, __VA_ARGS__);

// TBH THIS THING SUCKS HONESTLY. I HATE BOILERPLATE CODE.
// An ideal solution that I have come up in mind is that to have an function which based on what information given then would call the function
// Something like Katalyst::CoreLog(fatal, "Why are we still here? Just to suffer?")

// Macros for logging core

#define KL_CORE_TRACE(...)::Katalyst::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KL_CORE_DEBUG(...)::Katalyst::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define KL_CORE_INFO(...)::Katalyst::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KL_CORE_WARN(...)::Katalyst::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KL_CORE_ERROR(...)::Katalyst::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KL_CORE_CRITICAL(...)::Katalyst::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Macros for logging client

#define KL_TRACE(...)::Katalyst::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KL_DEBUG(...)::Katalyst::Log::GetClientLogger()->debug(__VA_ARGS__)
#define KL_INFO(...)::Katalyst::Log::GetClientLogger()->info(__VA_ARGS__)
#define KL_WARN(...)::Katalyst::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KL_ERROR(...)::Katalyst::Log::GetClientLogger()->error(__VA_ARGS__)
#define KL_CRITICAL(...)::Katalyst::Log::GetClientLogger()->critical(__VA_ARGS__)

// Forcefully enable assertion for now
#define KL_CORE_ASSERT(x, ...) {if (!(x)) {KL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap();}}
#define KL_ASSERT(x, ...) {if (!(x)) {KL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap();}}