#ifndef _AFFICHAGE_PLATEAU_H_
#define _AFFICHAGE_PLATEAU_H_

#include <SDL.h>

#define COLOR 32

SDL_Surface* init_window ();

void Affiche_hexagon (SDL_Surface* window, int cx, int cy, int rayon, Uint32 color);

void Affiche_plateau (SDL_Surface* window, SDL_Color color);

#endif /* _AFFICHAGE_PLATEAU_H_ */
