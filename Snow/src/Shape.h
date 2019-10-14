#pragma once
#include <SDL/SDL.h>

struct Color
{
	uint8_t r, g, b;
};

struct Shape
{
	double x, y;
	double dx, dy;
	Color c;
	
	virtual void draw(SDL_Surface* surf);	
};