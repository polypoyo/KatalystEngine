cmake_minimum_required(VERSION 3.19)

project(KatalystEngine)

# Find engine library packages
find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)
find_package(imgui CONFIG REQUIRED)

# Add ThirdParty subprojects
add_subdirectory("ThirdParty/glad") # Provides OpenGL 4.6 and Vulkan 1.3 Loaders

# Collect all source files
file(GLOB_RECURSE KATALYST_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h"
)

# Platform-specific configurations
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Building for Windows.")
    add_definitions(-DKL_ENGINE_EXPORT)

    # Check if Linux folder exists before excluding it
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Source/Platforms/Linux")
        list(FILTER KATALYST_SOURCES EXCLUDE REGEX ".*Platforms/Linux/.*")
    endif()

elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Building for Linux")

    # Check if Windows folder exists before excluding it
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Source/Platforms/Windows")
        list(FILTER KATALYST_SOURCES EXCLUDE REGEX ".*Platforms/Windows/.*")
    endif()
endif()

# Collect platform-specific source files
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Source/Platforms/${CMAKE_SYSTEM_NAME}")
    file(GLOB_RECURSE PLATFORM_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/Platforms/${CMAKE_SYSTEM_NAME}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/Platforms/${CMAKE_SYSTEM_NAME}/*.h"
    )
else()
    message(WARNING "Platform-specific folder for ${CMAKE_SYSTEM_NAME} does not exist.")
    set(PLATFORM_SOURCES "")
endif()


# Combine common and platform-specific sources
set(PROJECT_SOURCES ${KATALYST_SOURCES} ${PLATFORM_SOURCES})

# Debug specific configurations
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DKL_DEBUG_BUILD) # This will enable debug specific features.
endif()

# Create the shared library
add_library(KatalystEngine SHARED ${PROJECT_SOURCES})

# Add compiler defintions
target_compile_definitions(KatalystEngine PRIVATE GLFW_INCLUDE_NONE)

# Precompiled headers
target_precompile_headers(KatalystEngine PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/KatalystPCH.h"
)

# Specify include directories for the library
target_include_directories(KatalystEngine PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Source"
)

# Link dependencies from packages
target_link_libraries(KatalystEngine PUBLIC spdlog::spdlog_header_only glfw imgui::imgui)

# Link dependencies from ThirdParty
target_link_libraries(KatalystEngine PUBLIC glad)

# Link Platform-specific libraries
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(KatalystEngine PUBLIC dwmapi)
endif()

install(TARGETS KatalystEngine DESTINATION ./lib/)
