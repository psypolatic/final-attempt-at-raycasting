{ pkgs }: {
	deps = [
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
        pkgs.SDL2
        pkgs.SDL
        pkgs.valgrind
	];
}