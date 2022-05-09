#ifndef JOUEUR_H
#define JOUEUR_H
#include </usr/include/SDL/SDL.h>
#include </usr/include/SDL/SDL_image.h>
#include </usr/include/SDL/SDL_mixer.h>
#include </usr/include/SDL/SDL_ttf.h>
#define Hero_WIDTH 100
#define Hero_HEIGHT 100

typedef struct FRAME
{
        int i;  //num ligne imagette à afficher du sprite sheet
        int j;  //num colonne imagette à afficher du sprite sheet
}FRAME;
typedef struct
 {     SDL_Surface* texte;
       char t[20];
        SDL_Rect positionText;
        SDL_Color couleur;
        TTF_Font* police;
}text;

struct hero{
SDL_Surface * vie;
SDL_Surface * vie2;
SDL_Surface * vie3;
SDL_Surface * vie4;
        SDL_Rect posvie;
        SDL_Surface * image;
        SDL_Rect positionAnimation [4][4];
        FRAME Frame;
	int jump;
        SDL_Rect positionAbsolue;
        int nbvie;
        int score;
};
typedef struct hero Hero;
//void main1 ( int argc, char** argv );
void freeHero(Hero *H,text* txt);
void afficher(Hero * H,text* txt);
void initialiser(Hero *H,text* txt);
void animateHero(Hero *H,SDL_Event event);
void moveHero(Hero *H,SDL_Event event,SDL_Surface* screen);
void display_hero(Hero H, SDL_Surface* screen,text txt);
//void saut(SDL_Surface *screen,perso *pr,int *frame);
void jump_perso(Hero *p);
#endif


