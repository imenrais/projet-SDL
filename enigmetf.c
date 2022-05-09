#include "enigmetf.h"
 

//hatitlek l puts wl printf lkol f des commentaires
//zedt fonction enigme tekhdem lkhedma lkol


void InitEnigme(enigmetf *e, char nomfichier[])
{

	FILE *f = NULL;

	e->pos_selected = 0;
	e->rc = 0;
	e->background = IMG_Load("back.jpeg");
	e->button = IMG_Load("button.png");
	e->button_s = IMG_Load("button_s.png");

	if (TTF_Init() == -1 ) 
	printf("cant ttf \n " );
	
	SDL_Color couleur = {0, 0, 0};

	e->police = TTF_OpenFont("arial.ttf", 30);
	e->police1 = TTF_OpenFont("arial.ttf", 20);

	srand(time(NULL));
	e->num_question = rand() % 4;

	while (e->num_question == 0)
	{
		srand(time(NULL));
		e->num_question = rand() % 4;
	}
	//printf("%d \n ",e->num_question);
	

	char rep1[50];
	char rep2[50];
	char rep3[50];
	strcpy(rep1,"");
	strcpy(rep2,"");
	strcpy(rep3,"");
	int rc = 0 ; 

	f = fopen(nomfichier, "r");
	if (f != NULL)
	{
		fscanf(f, "%[^_]_%[^_]_%[^_]_%[^_]_%d", e->chquestion, rep1, rep2, rep3, &rc);
		int test = 1;
		while (test != e->num_question)
		{
			fscanf(f, "%[^_]_%[^_]_%[^_]_%[^_]_%d", e->chquestion, rep1, rep2, rep3, &rc);
			test++;
		}
		fclose(f);
	}
	srand(time(NULL));
	
	//puts(e->chquestion);
	//puts(rep1);
	//puts(rep2);
	//puts(rep3);
	e->rc = rc ;
	//printf ("%d \n ", e->rc);


	e->question = TTF_RenderText_Blended(e->police, e->chquestion, couleur);
	e->reponses[0] = TTF_RenderText_Blended(e->police1, rep1, couleur);
	e->reponses[1] = TTF_RenderText_Blended(e->police1, rep2, couleur);
	e->reponses[2] = TTF_RenderText_Blended(e->police1, rep3, couleur);
	e->pos_question.x = 270;
	e->pos_question.y = 270;

	e->pos_reponse1.x = 380;
	e->pos_reponse1.y = 500;

	e->pos_reponse2.x = 380 -240;
	e->pos_reponse2.y = 500;

	e->pos_reponse3.x = 380 + 240;
	e->pos_reponse3.y = 500 ;

	e->pos_reponse1txt.x = e->pos_reponse1.x + 50;
	e->pos_reponse1txt.y = e->pos_reponse1.y + 30;

	e->pos_reponse2txt.x = e->pos_reponse2.x + 50;
	e->pos_reponse2txt.y = e->pos_reponse2.y + 30;

	e->pos_reponse3txt.x = e->pos_reponse3.x + 50;
	e->pos_reponse3txt.y = e->pos_reponse3.y + 30;

	(*e).image_clock = IMG_Load("clock1.png");

	e->pos_image_clock.x = 500;
	e->pos_image_clock.y = 100;

	e->single_Clock.w = 57;
	e->single_Clock.h = 81;
	e->single_Clock.x = 0;
	e->single_Clock.y = 0;

	e->clock_num = 0;

	
}

void afficherEnigme(enigmetf e, SDL_Surface *ecran)
{

	SDL_BlitSurface(e.background, NULL, ecran, NULL);
	displayClock(e, ecran);
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);

	switch (e.pos_selected)
	{
	case 0:
		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
		break;

	case 1:
		SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
	
	break;
	case 2:
		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
	
	break;
	case 3:
		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
	
	break;
	}
}

int verify_enigme(enigmetf e, SDL_Surface *ecran)
{

	SDL_Rect pos = {160, 330};
	//printf ("%d \n ",e.pos_selected);
	//printf ("%d \n ",e.rc);


	if (e.pos_selected == e.rc)
	{
		printf("You win\n");
		SDL_Surface *win;
		win = IMG_Load("youwin.png");
		SDL_BlitSurface(win, NULL, ecran, &pos);SDL_Flip(ecran);
SDL_Delay(2000);return 1;
	}
	else
	{
		SDL_Surface *lost;
		lost = IMG_Load("youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		printf("You lost\n");SDL_Flip(ecran);
SDL_Delay(2000);return 0;
	}
	
}
void displayClock(enigmetf e, SDL_Surface *ecran)
{
	SDL_BlitSurface(e.image_clock, &(e.single_Clock), ecran, &e.pos_image_clock);
}
void animer(enigmetf *e)
{

	if (e->clock_num >= 0 && e->clock_num < 8)
	{
		e->single_Clock.x = e->clock_num * e->single_Clock.w;
		e->clock_num++;
	}

	if (e->clock_num == 8)
	{
		e->single_Clock.x = e->clock_num * e->single_Clock.w;
		e->clock_num = 0;
	}
}

void free_Surface_enigme(enigmetf *e)
{

	SDL_FreeSurface(e->background);
	SDL_FreeSurface(e->question);
	SDL_FreeSurface(e->reponses[0]);
	SDL_FreeSurface(e->reponses[1]);
	SDL_FreeSurface(e->reponses[2]);
	SDL_FreeSurface(e->button);
	SDL_FreeSurface(e->button_s);
}

int enigme(SDL_Surface *screen)
{
srand(time(NULL));
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(1024, 687, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	int continuer = 1;
	SDL_Event event;
	

	
	enigmetf e;
	InitEnigme(&e, "fichier.txt");

	while (continuer)
	{
		
		afficherEnigme(e, ecran);
		animer(&e);

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
			{
				continuer = 0;
			}
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_a:
					e.pos_selected = 1;
					break;

				case SDLK_b:
					e.pos_selected = 2;
					break;

				case SDLK_c:
					e.pos_selected = 3;
					break;

				case SDLK_RETURN:
					{
						verify_enigme(e, ecran);
						continuer = 0;
					}
					break;
				}
				break;
			case SDL_MOUSEMOTION:
			{
				if ((event.motion.x > e.pos_reponse1.x) && (event.motion.x < e.pos_reponse1.x + 240 ) && (event.motion.y > e.pos_reponse1.y) && (event.motion.y < e.pos_reponse1.y + 90))
				{
					e.pos_selected = 1;
				}
				else if ((event.motion.x > e.pos_reponse2.x) && (event.motion.x < e.pos_reponse2.x + 240) && (event.motion.y > e.pos_reponse2.y ) && (event.motion.y < e.pos_reponse2.y + 90))
				{
					e.pos_selected = 2;

				}
				else if ((event.motion.x > e.pos_reponse3.x) && (event.motion.x < e.pos_reponse3.x + 240) && (event.motion.y > e.pos_reponse3.y ) && (event.motion.y < e.pos_reponse3.y + 90))
				{
					e.pos_selected = 3;
				}
				else
					{
						e.pos_selected = 0;
					}
			}
			break;

			case SDL_MOUSEBUTTONDOWN:
				{
					if( event.button.button == SDL_BUTTON_LEFT )
					{
						if(e.pos_selected == 1 )
						{
							return verify_enigme(e,ecran);
							continuer = 0;
						}
						else if(e.pos_selected == 2 )
						{
							return verify_enigme(e,ecran);
							continuer = 0;
						}
						else if(e.pos_selected == 3 )
						{
							return verify_enigme(e,ecran);
							continuer = 0;
						}

					}
				}
				break;
			}
		}

		SDL_Flip(ecran);
	}
free_Surface_enigme(&e);
	TTF_CloseFont(e.police1);
	TTF_CloseFont(e.police);
}
