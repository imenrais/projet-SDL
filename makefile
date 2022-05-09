game:	joueur.o main.o 
	gcc main.o joueur.o -o game -lSDL -lSDL_image -lSDL_mixer  -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
menu.o:joueur.c
	gcc -c joueur.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

