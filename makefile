ngf: ngf.c global.c main.c network.c setup_allegro.c structure.c \
	settings.c input.c math_util.c structure.c plot_f.c F_and_f.c menu.c
	    clang-12 ngf.c -o ngf -lm -I/usr/include/x86_64-linux-gnu \
	    -lallegro -lallegro_primitives -lallegro_ttf -lallegro_font
	    ./ngf


