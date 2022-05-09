#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 900
#define SCREEN_H 765

typedef struct
{
	SDL_Surface *img;
	SDL_Surface *imgM;
	SDL_Rect posback;
	SDL_Rect posbackM;
	SDL_Rect camera;
	SDL_Rect cameraM;
	Mix_Music *son;


}Background;
typedef struct
{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;
}Personne;
void initBack(Background * b);
void initBackM(Background * b);
void aficherBack(Background b, SDL_Surface * screen);
void aficherBackM(Background b, SDL_Surface * screen);
void scrolling (Background *b,int direction,int pasavcment );
void animerBackground(Background *b);
//personne  
void initialiserperso(Personne *perso);
void deplacer_perso(Personne *perso,SDL_Event event);
void afficher_perso(SDL_Surface *screen,Personne perso);
void free_perso(Personne perso);
//collision
SDL_Color getpixel(SDL_Surface *psurface,int x,int y);
int collisionparfaite(SDL_Surface *psurface,SDL_Rect perso);
void collision(SDL_Surface *psurface,SDL_Rect *perso);
#endif  
