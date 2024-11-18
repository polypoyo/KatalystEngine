project(Sandbox)

find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)

# Collect all source files for Sandbox
file(GLOB_RECURSE PROJECT_SRC "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h")

# Add source files to this project's executable
add_executable(Sandbox ${PROJECT_SRC})

target_link_libraries(Sandbox PRIVATE spdlog::spdlog_header_only glfw)

# Link Sandbox to the KatalystEngine library
target_link_libraries(Sandbox PRIVATE KatalystEngine)

# Inherit include directories from KatalystEngine
target_include_directories(Sandbox PRIVATE "${CMAKE_SOURCE_DIR}/Engine/Source")

# Ensure KatalystEngine is available during runtime (Windows-specific DLL handling)
if (WIN32)
    add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:KatalystEngine>"
        "$<TARGET_FILE_DIR:Sandbox>"
    )
endif()
