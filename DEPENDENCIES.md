# Katalyst Engine Dependencies

The Katalyst Engine relies on several third-party libraries and tools to support its core functionality. These libraries are not directly included in this repository but can be managed using `vcpkg` or other package managers.

## Core Libraries

- **[Hazel Engine](https://github.com/TheCherno/Hazel)** - Apache 2.0 License
    - We're including this because this project is a recreation of the this project and we're resuing quite a lot too from this project.
- **[GLFW](https://www.glfw.org/)** - Zlib License
- **[glad2](https://github.com/Dav1dde/glad)** - MIT + Apache 2 Licenses
	- This project provides the OpenGL and Vulkan Loaders. Vulkan and OpenGL are trademarks of the Khronos Group Inc.
- **[spdlog](https://github.com/gabime/spdlog)** - MIT License
- **[imgui](https://github.com/ocornut/imgui)** - MIT License

## Build Tools and Compilers

- **[CMake](https://cmake.org/)** - OSL-3.0
- **[Ninja](https://ninja-build.org/)** - Apache License 2.0
- **[Clang](https://clang.llvm.org/)** - University of Illinois/NCSA Open Source License

## Package Management

- **[vcpkg](https://github.com/microsoft/vcpkg)** - MIT License

## Notes

For specific license terms, refer to each library's official documentation. Additional dependencies may be listed here as development progresses.

---

This document will be updated as new dependencies are introduced.

