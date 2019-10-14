#include "Circle.h"
#include "Helpers.h"
#include <memory>

Circle::Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	this->size = r;
	this->c.r = rand() % 256;
	this->c.g = rand() % 256;
	this->c.b = rand() % 256;
}

Circle::Circle(double x, double y, double r, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->size = r;
	this->vx = vx;
	this->vy = vy;
	this->c.r = rand() % 256;
	this->c.g = rand() % 256;
	this->c.b = rand() % 256;
}

void Circle::draw(SDL_Surface * s)
{
	double dr = size * size;
	for (double y = this->y - size; y <= this->y + size; ++y)
	{
		for (double x = this->x - size; x <= this->x + size; ++x)
		{
			double dx = x - this->x;
			double dy = y - this->y;
			if (dx*dx + dy * dy <= dr)
				Helpers::setPixel(s, x, y, c.r, c.g, c.b);
		}
	}
}
