
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "joueur.h"
#include "enigmetf.h"
#include "background.h"
int main ( int argc, char** argv )
{
Hero h;
text t;
char ch[100],ch1[100];
SDL_Surface* screen ;
 SDL_Event event;
        int continuer = 1;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
SDL_EnableKeyRepeat(60,60);
  SDL_WM_SetCaption("joueur", NULL);
Background b,bm;
	initBack(&b);
initBackM(&bm);
SDL_Surface *image,*image1;
int i=0,j=0;
	SDL_Rect posanim1 , posanim2;
	posanim1.x = 0;
        posanim1.y = 0;
        posanim2.x = 500;
        posanim2.y = 300;
   screen = SDL_SetVideoMode(750,450, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
initialiser(&h,&t);
afficher(&h,&t);
SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);//bch inajem yejry 
while(continuer)
        {
//animation 1


sprintf(ch,"%d.jpg",i);
SDL_Delay(20);
image=IMG_Load(ch);
if(rand()%2==1)i++;
if(i>3)
i=0;
 //animation 2
sprintf(ch1,"%d.png",j);
SDL_Delay(20);
image1=IMG_Load(ch1);
if(rand()%2==1)j++;
if(j>8)
j=0;
SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
 continuer = 0;
                break;
        }
aficherBack(b,screen);
			SDL_BlitSurface (image1,&(b.camera),screen,&posanim2);
     SDL_BlitSurface (image,&(b.camera),screen,&posanim1);
SDL_FreeSurface(image);image=NULL;
SDL_FreeSurface(image1);image1=NULL;
animateHero(&h, event);
moveHero(&h,event,screen);
if(h.positionAbsolue.x<100)
{scrolling (&b,1,10);scrolling (&bm,1,10);h.positionAbsolue.x=100;}
if(h.positionAbsolue.x>600)
{scrolling (&b,0,10);scrolling (&bm,1,10);h.positionAbsolue.x=600;}
if(h.positionAbsolue.y<100)
{scrolling (&b,2,4);scrolling (&bm,1,10);h.positionAbsolue.y=100;}
if(h.positionAbsolue.y>300)
{scrolling (&b,3,4);scrolling (&bm,1,10);h.positionAbsolue.y=300;}
display_hero(h,screen,t);

if(b.camera.x==2500)
return enigme(screen);
h.positionAbsolue.x+=b.camera.x;
h.positionAbsolue.y+=b.camera.y;
collision(bm.imgM,&h.positionAbsolue);
h.positionAbsolue.x-=b.camera.x;
h.positionAbsolue.y-=b.camera.y;
jump_perso(&h);
SDL_UpdateRect(screen, 0, 0, 0, 0);
if ( h.positionAbsolue.x < 0 ) {
      h.positionAbsolue.x = 0;
    }
    else if ( h.positionAbsolue.x > SCREEN_W-Hero_WIDTH) {
      h.positionAbsolue.x = SCREEN_W-Hero_WIDTH;
    }
    if ( h.positionAbsolue.y < 0 ) {
      h.positionAbsolue.y= 0;
    }
    else if ( h.positionAbsolue.y > SCREEN_H-Hero_HEIGHT ) {
      h.positionAbsolue.y = SCREEN_H-Hero_HEIGHT;
    }

                SDL_Flip(screen);

        }

freeHero(&h,&t);
TTF_Quit();
SDL_Quit();
}

