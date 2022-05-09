#include "joueur.h"
void afficher(Hero * H,text *txt)
{
        H->image = IMG_Load("t1.png");

        if(H->image == NULL) {
                printf("Unable to load Hero gif:%s\n", SDL_GetError());

        }
       
}


void initialiser(Hero* H,text* txt)
{
        int i, j;
        H->positionAbsolue.x = 0;
        H->positionAbsolue.y = 200;
        H->positionAbsolue.w = Hero_WIDTH;
        H->positionAbsolue.h = Hero_HEIGHT;
        H->Frame.i = 0;
        H->Frame.j = 0;
	H->jump=0;
        for (i = 0; i < 4; i++)
        {       for(j = 0; j < 4; j++)
                {
                        H->positionAnimation[i][j].x = j * Hero_WIDTH;
                        H->positionAnimation[i][j].y = i * Hero_HEIGHT;
                        H->positionAnimation[i][j].w = Hero_WIDTH;
                        H->positionAnimation[i][j].h = Hero_HEIGHT;
                }
        }
        

}


void display_hero(Hero H, SDL_Surface* screen,text txt)
{
        
        SDL_BlitSurface(H.image, &H.positionAnimation[H.Frame.i][H.Frame.j],  screen, &H.positionAbsolue);

}

void animateHero(Hero *H,SDL_Event event)
{
switch(event.type)
{
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
              case SDLK_RIGHT: // Flèche droite
                        H->Frame.i = 2;
                        H->Frame.j ++;
                        if (H->Frame.j == 4)
                                H->Frame.j = 0;
                       break;
 case SDLK_LEFT: // Flèche gauche
                        H->Frame.i = 1;
                        H->Frame.j ++;
                        if (H->Frame.j == 4)
                                H->Frame.j = 0;
                        break;


   case SDLK_UP: // Flèche haut
                      H->Frame.i = 3;
                        H->Frame.j ++;
                        if (H->Frame.j ==4)
                       H->Frame.j = 0;

                        break;
                    case SDLK_DOWN: // Flèche bas
                         H->Frame.i = 0;
                        H->Frame.j ++;
                        if (H->Frame.j ==4)
                                H->Frame.j = 0;

                        break;
 case SDLK_d:
 H->Frame.i = 2;
                        H->Frame.j ++;
                        if (H->Frame.j == 4)
                                H->Frame.j = 0;
break ;
 case SDLK_q: // Flèche gauche
H->Frame.i = 1;
                        H->Frame.j ++;
                        if (H->Frame.j == 4)
                                H->Frame.j = 0;
                        break;
                     break;
        }
        break;
}
SDL_Delay(1);
}

void moveHero(Hero *H, SDL_Event event,SDL_Surface* screen)
{
    //int acc=1;
switch(event.type)
{
        case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
              case SDLK_RIGHT: // Flèche droite
H->positionAbsolue.x +=10;//20
                       break;
            case SDLK_LEFT: // Flèche gauche
H->positionAbsolue.x -=10;//20
                     break;

 case SDLK_UP:
H->positionAbsolue.y -=4;
break;
 case SDLK_DOWN:
H->positionAbsolue.y +=4;
break ;
 case SDLK_d:
H->positionAbsolue.x +=10;
break ;
 case SDLK_q: // Flèche gauche
H->positionAbsolue.x -=10;//20
                     break;


 }
        break;
}
}



void freeHero(Hero *H,text* txt)
{
        SDL_FreeSurface(H->image);
        SDL_FreeSurface(H->vie);
        SDL_FreeSurface(txt->texte);
}
    void jump_perso(Hero *p)
{
SDLMod modstate = SDL_GetModState();       
if(modstate == 4160)if((*p).jump ==0) (*p).jump = 1;
if((*p).jump>0){if ((*p).jump <4) (*p).jump ++;else (*p).jump=-1;}
if((*p).jump<0){if ((*p).jump >-4) (*p).jump --;else (*p).jump=0;}
(*p).positionAbsolue.y-=(*p).jump*5;
}    
/*void saut(SDL_Surface *screen,Hero *H,int *frame)
{
    int s=H->pp.y;
    if((*frame)<3)
    {
    H->pp.x+=10;
    H->pp.y = -0.04*((H->pp.x)*(H->pp.x))+100;
    void afficher(Hero * H,text* txt);
    SDL_Delay(50);
    }else
    {
    H->pp.x-=10;
    H->pp.y=-0.04*((H->pp.x)*(H->pp.x))+100;
    void afficher(Hero * H,text* txt);
    SDL_Delay(50);
    }
    if(H->pp.y<s)
    {
        H->pp.y=500;
    }
}*/

