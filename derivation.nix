{
  pkgs,
  stdenv,
  lib,
  ...
}: stdenv.mkDerivation {
    pname = "katalyst";
    version = "0.0";

    src = ./.;

    nativeBuildInputs = with pkgs; [
      cmake
      vcpkg
      ninja
    ];
    buildInputs = with pkgs; [
      spdlog
      # For some reason, regular glfw-wayland
      # doesn't work. So, we have to use this
      # version intended for Minecraft. Logic.
      glfw-wayland-minecraft
    ];

    meta = {
      mainProgram = "Sandbox";
      platforms = lib.platforms.linux;
      maintainers = [];
    };
  }
