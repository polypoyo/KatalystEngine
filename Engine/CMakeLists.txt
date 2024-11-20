cmake_minimum_required(VERSION 3.19)

project(KatalystEngine)

# Find engine library packages
find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)

# Collect all source files
file(GLOB_RECURSE KATALYST_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h"
)

# Platform-specific configurations
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Building for Windows.")
    add_definitions(-DKL_ENGINE_EXPORT)

    # Exclude Linux platform files
    list(FILTER KATALYST_SOURCES EXCLUDE REGEX ".*Platforms/Linux/.*")

elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Building for Linux")

    # Exclude Windows platform files
    list(FILTER KATALYST_SOURCES EXCLUDE REGEX ".*Platforms/Windows/.*")
endif()

# Collect platform-specific source files
file(GLOB_RECURSE PLATFORM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Platforms/${CMAKE_SYSTEM_NAME}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Platforms/${CMAKE_SYSTEM_NAME}/*.h"
)

# Combine common and platform-specific sources
set(PROJECT_SOURCES ${KATALYST_SOURCES} ${PLATFORM_SOURCES})

# Log the filtered sources (optional, for debugging)
#message(STATUS "Filtered sources: ${PLATFORM_SOURCES}")

# Create the shared library
add_library(KatalystEngine SHARED ${PROJECT_SOURCES})

# Precompiled headers
target_precompile_headers(KatalystEngine PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/KatalystPCH.h"
)

# Specify include directories for the library
target_include_directories(KatalystEngine PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Source"
)

# Link dependencies
target_link_libraries(KatalystEngine PUBLIC spdlog::spdlog_header_only glfw)

# Link Platform-specific libraries
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(KatalystEngine PUBLIC dwmapi opengl32)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(KatalystEngine PUBLIC GL)
endif()

install(TARGETS KatalystEngine DESTINATION ./lib/)
