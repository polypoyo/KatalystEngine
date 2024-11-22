# glad2/CMakeLists.txt
project(glad)

# Create a library for glad2 (OpenGL and Vulkan loaders)
add_library(glad STATIC
    src/gl.c       # OpenGL loader
    src/vulkan.c   # Vulkan loader
)

# Add this line to enable -fPIC
set_target_properties(glad PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Add include directories for glad headers
target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link glad2 to other targets in the project
target_compile_definitions(glad PUBLIC GLAD_GLAPI_EXPORT)

# Optionally set specific OpenGL/Vulkan flags if needed
if(WIN32)
    target_compile_definitions(glad PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
