#include "background.h"

void initBack(Background * b)
{
b->img =IMG_Load("map.jpg");                               //IMG_Load 
b->posback.x = 0;
 b->posback.y = 0;
 
b->camera.x =0;
  b->camera.y =0;
  b->camera.w = 3840;
  b->camera.h =720; 
  }
  
  void initBackM(Background * b)
 { 
 b->imgM =SDL_LoadBMP("mapm.bmp");
 b->posbackM.x = 0;
 b->posbackM.y = 0;
 
  b->cameraM.x =0;
  b->cameraM.y =0;
  b->cameraM.w =3840;
  b->cameraM.h =720;
}
void aficherBack(Background b, SDL_Surface * screen)
{
SDL_BlitSurface(b.img,&(b.camera),screen,&b.posback);
}  
/*void aficherBackM(Background b, SDL_Surface * screen)
{
SDL_BlitSurface(b.imgM,&(b.cameraM),screen,&b.posbackM);
} 
*/
void scrolling (Background *b,int direction,int pasavcment )
{
      
if (direction ==0)if(b->camera.x<2700){   //droite
	b->camera.x+= pasavcment;    
	b->cameraM.x+= pasavcment;
	
        }
 if (direction ==1)if(b->camera.x>pasavcment)   { //gauche          
	b->camera.x-=pasavcment; 

	b->cameraM.x-=pasavcment; 
	}

	if (direction ==2)if(b->camera.y>pasavcment){//up 
        b->camera.y-= pasavcment;

         b->cameraM.y-=pasavcment;
	}
 if (direction ==3)if(b->camera.y<550){//down          
        b->camera.y+= pasavcment;

	 b->cameraM.y+= pasavcment;
	 }

}
//personne 
void initialiserperso(Personne *perso)
{	
	perso->image_p=IMG_Load("hero.png");
	perso->pos_perso.x=0;
	perso->pos_perso.y=150;
	perso->pos_perso.w=80;
	perso->pos_perso.h=168;
}

void afficher_perso(SDL_Surface *screen,Personne perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso);
}

void deplacer_perso(Personne *perso,SDL_Event event)
{	
SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            perso->pos_perso.y=perso->pos_perso.y-10;
                            break;
                        case SDLK_DOWN:
                            perso->pos_perso.y=perso->pos_perso.y+10;
                            break;
                        case SDLK_RIGHT:
                            perso->pos_perso.x=perso->pos_perso.x+10;
                            break;
                        case SDLK_LEFT:
                            perso->pos_perso.x=perso->pos_perso.x-10;
                            break;
                        }
                 break;
             }
}


void free_perso(Personne perso)
{
	SDL_FreeSurface(perso.image_p);
}
 // collision
 
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int  collisionparfaite(SDL_Surface *psurface,SDL_Rect p)
{	
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=p.x;
	tabx[1]=(p.x)+((p.w)/2);
	tabx[2]=(p.x+p.w);
	tabx[3]=p.x;
	tabx[4]=p.x;
	tabx[5]=(p.x)+((p.w)/2);
	tabx[6]=(p.x+p.w);
	tabx[7]=(p.x+p.w);
	taby[0]=p.y;
	taby[1]=p.y;
	taby[2]=p.y;
	taby[3]=(p.y)+((p.h)/2);
	taby[4]=(p.y+p.h);
	taby[5]=(p.y+p.h);
	taby[6]=(p.y+p.h);
	taby[7]=(p.y)+((p.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;

	}
	}
	return 10;
	
}	

void collision(SDL_Surface *psurface,SDL_Rect *p)
{	int i;
	i=collisionparfaite(psurface,*p);

	switch (i)
	{
		case 0 :p->y=p->y+10;
			break;
		case 1 :p->y=p->y+10;
			 break;
		case 2 :p->y=p->y+10;
			break;
		case 3 :p->x=p->x+10;
			break;
		case 4 :p->y=p->y-10;
			break;
		case 5 :p->y=p->y-10; 
			break;
		case 6 :p->y=p->y-10; 
			break;
		case 7 :p->x=p->x-10;
			break;
		

	}
}



