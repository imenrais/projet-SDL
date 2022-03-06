#ifndef Perso_H
#define Perso_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void initPerso(Personne *p);
void afficherPerso(Personne p,SDL_Surface * screen);
void deplacerPerso(Personne *p,int dt);
void animerPerso(Personne *p);
void saut(Personne *p);
#endif
