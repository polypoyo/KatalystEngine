# The Katalyst Engine Project
[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

An in-house, experimental, ground-up recreation of the [Hazel Engine](https://github.com/TheCherno/Hazel). While much of the architecture follows the Hazel Engine series, we have additional requirements that extend beyond the series' scope. Another reason for not directly forking Hazel is to deepen our understanding of engine development, allowing us to learn and maintain complete control over the games we aim to produce at OpenNullanoid.

The engine project is an explicit C++20 CMake/Ninja project using the Clang compiler for cross-platform compilation. We're currently focusing on supporting Windows and Linux platforms.

## Building the project (Contribution/Testing)
As we're still in the planning phase, we can't provide exact details as it might be inaccurate. 

But in order to build the project you'll need to make sure of a few things:
- Operating system Software Development Kits (SDKs) needs to be installed
    - For Windows, install Visual Studio 2022 with the latest Windows SDK installed
    - For Linux distributions, refer to your wiki/manual and install packages such as `build-essential` (Ubuntu/Debian) or `base-devel` (Arch/Endeavour/CatchyOS).
- Building tools for this project needs to be installed
    - Install **LLVM/Clang (C/C++ Compiler), CMake(Generator for Buildsystem), Ninja (Buildsystem), Git (Version Control System)**
- Resolve dependencies for the project
    - Run `git clone https://github.com/microsoft/vcpkg` and in the git repository folder initialize **VCPKG** by running `bootstrap-vcpkg` script
    - Register the `VCPKG_ROOT` enviourment variable witht the path of your VCPKG installation (e.g `/home/user/vcpkg`) and also add the path to the `PATH` enviorment variable to have access the `vcpkg` executable.
    - Run `vcpkg integrate install` if you want to integrete vcpkg with your shell/machine. (Optional)
    - Install the dependencies using `vcpkg install` in the project root directory.
    - **Addtional Note:** Linux users might be able to fetch these packages using thier native package managers. It's highly recommended to get `glfw3-wayland` package for wayland support from native package vendors instead of VCPKG.
        - You can look into what packages are being used by the engine and/or other subprojects by checking thier `CMakeLists.txt` file in the subfolders.
****
For building the project first list out the avaiable **configuration** presets:
```pwsh
cmake --preset none
# You'd find these presets here probably along with an error which is okay to ignore
  "linux-x64-debug"     - Linux x86_64 Debug
  "linux-x64-release"   - Linux x86_64 Release
  "windows-x64-debug"   - Windows x86_64 Debug
  "windows-x64-release" - Windows x86_64 Release
```
Then once you've picked your appropriate preset, configure and build the engine by running:
```pwsh
cmake --preset linux-x64-debug # linux-x64-debug is shown as an example here. It'll configure your project to be used
cmake --build --preset build-linux-x64-debug # add "build-" before your chosen configured configuration to build the project
```
After the build is complete you can test out the engine and it's functionality by running the sandbox executable found in the `Output/Build/<Your Chosen Configuration>/Sandbox/Sandbox` in a terminal.


## Copyright Notice
© 2024-2025 [Kaabir Akeemuzzaman](https://github.com/Kabir404) and the [OpenNullanoid](https://github.com/OpenNullanoid) Contributors.

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License in this project’s `LICENSE.md` file or at the [Apache 2.0 License site](https://opensource.org/licenses/Apache-2.0).

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

---

This project is currently in its initial stages, and much of its structure is derived from the [Hazel Engine](https://github.com/TheCherno/Hazel). However, we aim to implement additional features and customizations as development progresses. The dependencies and any third-party components are not directly included in this repository; instead, they are detailed in the [DEPENDENCIES.md](DEPENDENCIES.md) file, where you can find information on their licenses and attributions.
