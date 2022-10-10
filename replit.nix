{ pkgs }: {
	deps = [
    pkgs.nano
    pkgs.cc65
    pkgs.gcc
    pkgs.binutils
		pkgs.vim
    pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}