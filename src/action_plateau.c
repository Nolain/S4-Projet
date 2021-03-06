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

#define J1 1//Le joueur 1 va de haut en bas et le J2 de gauche à droite
#define J2 2
#define VIDE 0
#define larg_plat 9
#define long_plat 9

int [long_plat][larg_plat] Plateau;

void jouer_coup ( int couleur_joueur, int[long_plat][larg_plat] Plateau , int x , int y )
{
	Plateau[x][y]=couleur_joueur;
}

bool TestGagnant(int x,int y)
{
	bool a[]={false,false,false};
	if (y=larg_plat)
	{
		return true;
	}
	else
	{
		if(Plateau[x][y+1]==J1 )
		{
			a[0]= touchelebout(x,y+1);
		}
		else if (Plateau[x+1][y]==J1)
		{
			a[1]= touchelebout(x+1,y);
		}
		else if (Plateau[x-1][y]==J1)
		{
			a[2]= touchelebout(x-1,y);
		}
	}
	return (a[0]||a[1]||a[2]);
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
