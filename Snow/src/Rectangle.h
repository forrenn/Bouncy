#pragma once
#include "Shape.h"
struct Rectangle : Shape
{
	double height;

	virtual void draw(SDL_Surface* surf);
	virtual double width();
	virtual double area();
};