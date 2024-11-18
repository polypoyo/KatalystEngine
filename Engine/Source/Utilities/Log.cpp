#include "Utilities/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Katalyst 
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() 
	{
		// Sets up the pattern to be used in all logger threads.
		spdlog::set_pattern("[%T %D] %^%n.%l >> %v%$");

		// Initializes the logger threads for both Client and Core.
		s_CoreLogger = spdlog::stdout_color_mt("Katalyst");
		s_ClientLogger = spdlog::stdout_color_mt("Application");

		// Sets up the log level for individual logger threads.
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger->set_level(spdlog::level::trace);

		KL_CORE_INFO("Log has been initialized. Powered by SPDLOG.");
	}
}