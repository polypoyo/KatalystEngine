let
  pkgs = import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/c26faf0c26de27cd38468fb25b2275765d78d087.tar.gz") { };
in
pkgs.callPackage ./derivation.nix { }
