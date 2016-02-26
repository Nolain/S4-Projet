#include <affichage_menu_principal.h>

void Affichage_menu_pricipal (SDL_Surface* window)
{
	Uint32 color_entries = SDL_MapRGB (fenetre->format, rand()%255, rand()%255, rand()%255);
	SDL_Surface* entry;
	
	/* Jouer */
	entry = SDL_CreateRGBSurface (SDL_HWSURFACE, ,  , window->format->BitsPerPixel, 0, 0, 0, 0);
	SDL_FillRect (entry, NULL, color_entries);
	
	
}
