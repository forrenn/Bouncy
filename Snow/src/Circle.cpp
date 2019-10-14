#include "Circle.h"
#include "Helpers.h"
#include <memory>

Circle::Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	this->radius = r;
	this->c.r = rand() % 256;
	this->c.g = rand() % 256;
	this->c.b = rand() % 256;
}

Circle::Circle(double x, double y, double r, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->radius = r;
	this->vx = vx;
	this->vy = vy;
	this->c.r = rand() % 256;
	this->c.g = rand() % 256;
	this->c.b = rand() % 256;
}

void Circle::draw(SDL_Surface * s)
{
	double dr = radius * radius * 0.25;
	double r_half = radius / 2;
	for (double y = this->y - r_half; y < this->y + r_half; ++y)
	{
		for (double x = this->x - r_half; x < this->x + r_half; ++x)
		{
			double dx = x - this->x;
			double dy = y - this->y;
			if (dx*dx + dy * dy <= dr)
				Helpers::setPixel(s, x, y, c.r, c.g, c.b);
		}
	}
}
