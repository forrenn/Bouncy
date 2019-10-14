#include "Shape.h"

void Shape::draw(SDL_Surface * surf)
{

}

void Shape::updatePos(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double maxY)
{
	this->x += vx * dt;
	this->y += vy * dt;

	if (x > maxX || x < 0) vx = -vx;
	if (y > maxY || y < 0) vy = -vy;
}

void Shape::update(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double maxY)
{
	updatePos(dt, shapes, maxX, maxY);
}
