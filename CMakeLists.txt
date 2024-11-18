# CMakeLists for the Project Root
cmake_minimum_required(VERSION 3.19)
project ("KatalystProject")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Add subprojects for building
add_subdirectory("Engine")
add_subdirectory("Sandbox")

# Ensure Sandbox waits for FirelightEngine to finish building
add_dependencies(Sandbox KatalystEngine)
