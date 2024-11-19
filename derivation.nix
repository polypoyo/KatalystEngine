{
  pkgs,
  stdenv,
  lib,
  ...
}: let
  staticSDL2 = pkgs.SDL2.overrideAttrs (old: {
    dontDisableStatic = true;
  });
in
  stdenv.mkDerivation {
    pname = "katalyst";
    version = "0.0";

    src = ./.;

    nativeBuildInputs = with pkgs; [staticSDL2 staticSDL2.dev cmake vcpkg ninja ];
    buildInputs = with pkgs; [ spdlog glfw ];

    meta = {
      mainProgram = "katalyst";
      platforms = lib.platforms.linux;
      maintainers = [];
    };
  }
