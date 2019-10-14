#pragma once
#include "Shape.h"
struct Circle : Shape
{
	Circle(double x, double y, double r);
	double radius;
	void draw(SDL_Surface* s) override;
};