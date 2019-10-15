#pragma once
#include "Shape.h"
struct Circle : Shape
{
	Circle(double x, double y, double r);
	Circle(double x, double y, double r, double vx, double vy);
	Circle(double x, double y, double z, double r, double vx, double vy, double vz);

	void draw(SDL_Surface* s) override;
};