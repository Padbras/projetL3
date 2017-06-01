with import <nixpkgs> {}; 

stdenv.mkDerivation {
    name = "client-server";
    buildInputs = [ stdenv cmake pkgconfig sfml ];
    src = ./.;
}

