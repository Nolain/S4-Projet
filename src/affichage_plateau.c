#include "affichage_plateau.h"

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 1200
#define HEIGHT 700
#define NBSIDE 11
#define PI 3.14159265

#define SQ(a) a * a

//gcc -Wall -std=c99 `sdl-config --cflags --libs` -g -lm -o plateau plateau.c

/* Internes */
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

void Central_Square (SDL_Surface* window, Sint16* x, Sint16* y, Uint32 color)
{
	int width = x[0] - x[2];
	int height = y[2] - y[3];
	
	SDL_Surface* square = SDL_CreateRGBSurface (SDL_HWSURFACE, width, height, 32, 0, 0, 0, 0);
	SDL_FillRect (square, NULL, color);
	SDL_Rect position = {x[3], y[3]};
	SDL_BlitSurface (square, NULL, window, &position);
	SDL_FreeSurface (square);
}

void Triangles (SDL_Surface* window, Sint16* x, Sint16* y, Uint32 color)
{
	int h = y[1] - y[2];
	int l = (x[0] - x[2])/2;
	for (int j = 0; j < h; ++j)
		for (int i = - l * (h - j) / h; i <= l * (h - j) / h; ++i)
		{
			putpixel (window, x[1] + i - 1, y[3] - j, color);
			putpixel (window, x[1] + i - 1, y[0] + j, color);
		}
}

void Quadrille (SDL_Surface* window, int margeh, int margev, int ecart, int rayon, SDL_Color color)
{
	for (int i = 0; i < NBSIDE; ++i)
	{
		int dx = margeh + rayon * cos(PI/6) + i * (2 * rayon * cos(PI/6) + 2 * ecart * cos(PI/3));
		for (int j = 0; j < NBSIDE; ++j)
		{
			int y = margev + rayon + j * (1.5 * rayon + ecart * sin(PI/3));
			int x = dx + j * (rayon * cos(PI/6) + ecart * cos(PI/3));
			Affiche_hexagon (window, x, y, rayon, SDL_MapRGB(window->format, color.r, color.g, color.b));
		}
	}
}

/*Externes*/

SDL_Surface* init_window ()
{
	if (SDL_Init (SDL_INIT_VIDEO))
		fprintf (stderr, "Erreur d'inistialisation SDL : %s\n", SDL_GetError());
	
	SDL_Surface* window = SDL_SetVideoMode (WIDTH, HEIGHT, COLOR, SDL_HWSURFACE | SDL_RESIZABLE);
	SDL_FillRect (window, NULL, SDL_MapRGB(window->format, 0, 0, 0));
	SDL_Flip (window);
	return window;
}

void Affiche_hexagon (SDL_Surface* window, int cx, int cy, int rayon, Uint32 color)
{
	Sint16 x [6];
	Sint16 y [6];
	for (int i = 0; i < 6; ++i)
	{
		x [i] = cos(i * PI/3 + PI/6) * rayon + cx;
		y [i] = sin(i * PI/3 + PI/6) * rayon + cy;
	}
	Central_Square (window, x, y, color);
	Triangles (window, x, y, color);
	
	/*
	for (int j = 0; j < window->w; ++j)
			putpixel (window, j, cy, SDL_MapRGB(window->format, 0, 255, 0));
	for (int j = 0; j < window->h; ++j)
			putpixel (window, cx, j, SDL_MapRGB(window->format, 0, 0, 255));
	*/
	
	SDL_Flip (window);
}

void Affiche_plateau (SDL_Surface* window, SDL_Color color)
{
	int margeh = 100;
	int margev = 40;
	int width = window->w - 2 * margeh;
	int height = window->h - 2 * margev;
	int ecart = 10;
	int r1 = (height - (NBSIDE - 1) * ecart * sin(PI/3)) / (.5 + NBSIDE * 1.5); 
	int r2 = (width - (3 * NBSIDE - 1) * ecart * .5) / ((3 * NBSIDE - 1) * cos (PI/6));
	if (r1 < r2)
	{
		Quadrille (window, margeh, margev, ecart, r1, color);
	}
	else
	{
		Quadrille (window, margeh, margev, ecart, r2, color);
	}
}

/*int main (int argc, char* argv[])
{
	
	SDL_Color c = {255, 0, 0};
	vector_t ce = {100, 100};
	int r = 100;
	Affiche_hexagon (window, ce.x, ce.y, r, c);
	
	vector_t ce2 = {ce.x + r*cos(PI/6) + 1, ce.y + r + r / 2 + 1};
	
	Affiche_hexagon (window, ce2.x, ce2.y, r, c);
	
	Affiche_plateau (window, c);
	//polygonRGBA(SDL_Surface* window,Sint16* vx, Sint16* vy,int n,Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	
	bool end = false;
	
	while (!end)
	{
		SDL_Event event;
		SDL_WaitEvent (&event);
		switch (event.type)
		{
			case SDL_VIDEORESIZE:
				window = SDL_SetVideoMode (event.resize.w, event.resize.h, COLOR, SDL_HWSURFACE | SDL_RESIZABLE);
				Affiche_plateau (window, c);
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
