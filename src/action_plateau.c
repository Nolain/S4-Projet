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

int [larg_plat][long_plat] Plateau;


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
