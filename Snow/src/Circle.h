#pragma once
#include "Shape.h"
struct Circle : Shape
{
	Circle(double x, double y, double r);
	Circle(double x, double y, double r, double vx, double vy);

	virtual void draw(SDL_Surface* s);
	virtual void onWallCollision();
	virtual double area();
};