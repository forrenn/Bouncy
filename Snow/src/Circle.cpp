#include "Circle.h"
#include "Helpers.h"
#include <memory>

Circle::Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	z = 0;
	vz = 0;
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

Circle::Circle(double x, double y, double z, double r, double vx, double vy, double vz)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->size = r;
	this->vx = vx;
	this->vy = vy;
	this->vz = vz;
	this->c.r = rand() % 256;
	this->c.g = rand() % 256;
	this->c.b = rand() % 256;
}

void Circle::draw(SDL_Surface * s)
{
	if (z == 0) return;
	double scaled_size = size / z;
	double dr = scaled_size * scaled_size;
	for (double y = this->y - scaled_size; y <= this->y + scaled_size; ++y)
	{
		for (double x = this->x - scaled_size; x <= this->x + scaled_size; ++x)
		{
			double dx = x - this->x;
			double dy = y - this->y;
			if (dx*dx + dy * dy <= dr)
				Helpers::setPixel(s, x, y, c.r, c.g, c.b);
		}
	}
}
