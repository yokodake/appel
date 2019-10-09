{ pkgs ? (import <nixpkgs> {})
, source ? ./.
, version ? "dev"
} :

with pkgs;

clangStdenv.mkDerivation {
    name = "appel-${version}";
    inherit version;
    src = lib.cleanSource source;
    buildInputs = [ makeWrapper bison flex ];
    enableParallelBuilding = true;
}
