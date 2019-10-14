#pragma once
#include <SDL/SDL.h>
struct Shape
{
	double x, y;
	
	void draw(SDL_Surface* surf);
};