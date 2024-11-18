#pragma once

constexpr auto KL_NAME_FANCY = "Katalyst Engine";
constexpr auto KL_VERSION = "EARLY_DEVELOPMENT";
constexpr auto KL_COPYRIGHT_STRING = "Copyright (C) 2024-2025 Kaabir Akeemuzzman and OpenNullanoid Contributors.";

// Intended for Katalyst applications.
#include "Core/Core.h" // Contains macros for API calls
#include "Core/Application.h" // Contains the application class for client applications
#include "Core/EntryPoint.h" // Entry point for client applications.
#include "Layers/Layer.h" // Allowing to create layers for client applications.
#include "Utilities/Log.h" // The logger class along with access to logging macros