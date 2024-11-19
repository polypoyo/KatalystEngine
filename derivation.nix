{
  pkgs,
  stdenv,
  lib,
  ...
}: stdenv.mkDerivation {
    pname = "katalyst";
    version = "0.0";

    src = ./.;

    nativeBuildInputs = with pkgs; [ cmake vcpkg ninja ];
    buildInputs = with pkgs; [ spdlog glfw ];

    meta = {
      mainProgram = "katalyst";
      platforms = lib.platforms.linux;
      maintainers = [];
    };
  }
