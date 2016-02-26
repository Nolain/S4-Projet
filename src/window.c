#include "window.h"

#define COLOR 32
#define WIDTH 640
#define HEIGHT 480

SDL_Surface* init_window ()
{
	if (SDL_Init (SDL_INIT_VIDEO))
		fprintf (stderr, "Erreur d'inistialisation SDL : %s\n", SDL_GetError());
	
	SDL_Surface* window = SDL_SetVideoMode (WIDTH, HEIGHT, COLOR, SDL_HWSURFACE | SDL_RESIZABLE);
	SDL_FillRect (window, NULL, SDL_MapRGB(window->format, 0, 0, 0));
	SDL_Flip (window);
	return window;
}
