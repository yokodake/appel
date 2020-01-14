{ pkgs ? (import <nixpkgs> {})
, source ? ./.
, version ? "dev"
} :

with pkgs;

stdenv.mkDerivation {
    name = "appel-${version}";
    inherit version;
    src = lib.cleanSource source;
    buildInputs = [ makeWrapper bison flex cmake ];
    enableParallelBuilding = true;
}
