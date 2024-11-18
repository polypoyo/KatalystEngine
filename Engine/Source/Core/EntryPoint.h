#pragma once

#include "Katalyst.h"
#include "Application.h"
#include "Utilities/Log.h"

#if defined(_WIN32) || defined(__CYGWIN__) || defined(__linux__) || defined(__unix__)

// Declare CreateApplication function that the client application should define
extern Katalyst::Application* Katalyst::CreateApplication();

int main(int argc, char** argv)
{
    // Print project information
    std::cout << "  " << KL_NAME_FANCY << " Version: " << KL_VERSION << std::endl;
    std::cout << "  " << KL_COPYRIGHT_STRING << std::endl;
    std::cout << "  Compiled on: " << __TIMESTAMP__ << std::endl;

    // Initialize logging
    Katalyst::Log::Init(); // <<--- This is broken
    KL_CORE_WARN("{} is in early stages of development.", KL_NAME_FANCY);

    // Create and run the application
    auto app = Katalyst::CreateApplication(); // <<-- Alright it found Katalyst::CreateApplication but Never found Application constructor???????????
    app->Run();
    delete app;
    return 0;
}

#else
#error "Unsupported platform for the entry point."
#endif
