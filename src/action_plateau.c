//#include "action_plateau.h"

#include <stdbool.h>
#include "affichage_plateau.h"

void Resize_window (SDL_Surface* window, const SDL_ResizeEvent* resize)
{
	SDL_Color color = {255, 0, 0};
	window = SDL_SetVideoMode (resize->w, resize->h, COLOR, SDL_HWSURFACE | SDL_RESIZABLE);
	Affiche_plateau (window, color);
}

void Surbrillance (SDL_Surface* window)
{
	
}

#define ROUGE 1
#define BLEU 2
#define VIDE 0
#define larg_plat 9
#define long_plat 9

int [long_plat][larg_plat] Plateau;

void jouer_cou ( int couleur_joueur, int[long_plat][larg_plat] Plateau , int x , int y )
{
	Plateau[x][y]=couleur_joueur;
}

bool couleur_in_case_adjacente (int couleur_joueur, int[long_plat][larg_plat] Plateau , int x, int y)
{
	bool a;
	switch (x):
	{
		case 1: switch (y):
				{
					case 1: if ((Plateau[1][2] == couleur_joueur) ||(Plateau[2][1] == couleur_joueur) ||(Plateau[2][2] == couleur_joueur))
						{
							a=true;
						}
						else
						{
							a=false
						}
						break;
					case larg_plat: if ((Plateau[x][y-1] == couleur_joueur) ||(Plateau[y][x+1] == couleur_joueur))
						{
							a=true;
						}
						else
						{
							a=false
						}
						break;
					default :  if ((Plateau[x][y+1] == couleur_joueur) ||(Plateau[x+1][y] == couleur_joueur) ||(Plateau[x+1][y+1] == couleur_joueur))
						{
							a=true;
						}
						else
						{
							a=false
						}
				}
		case : long_plat:
	}
}

bool cou_possible (int couleur_joueur,int[larg_plat][long_plat] Plateau , int x, int y)
{
	bool possible;
	if (Plateau[x][y]==0)
	{
		if (couleur_in_case_adjacente(couleur_joueur, Plateau, x, y))
		{
			possible=true;
		}
	}
	else
	{
		possbile=false;
	}
	return possible;
}

/*int main ()
{
	SDL_Surface* window = init_window();
	SDL_Color color = {255, 0, 0};
	Affiche_plateau (window, color);
	bool end = false;
	
	while (!end)
	{
		SDL_Event event;
		SDL_WaitEvent (&event);
		switch (event.type)
		{
			case SDL_MOUSEMOTION:
				
				break;
			case SDL_VIDEORESIZE:
				Resize_window (window, &(event.resize));
				break;
			case SDL_QUIT:
				end = true;
				break;
		}
	}
	SDL_FreeSurface (window);
	SDL_Quit ();
	return 0;
}*/
