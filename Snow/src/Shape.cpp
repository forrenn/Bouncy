#include "Shape.h"

void Shape::draw(SDL_Surface * surf)
{

}

void Shape::updatePos(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double maxY)
{
	vy += 9.81*dt;
	this->x += vx * dt;
	this->y += vy * dt;

	if (x + size > maxX || x - size < 0) vx = -vx;
	if (y + size > maxY || y - size < 0) vy = -vy;

	for (size_t i = 0; i < shapes.size(); ++i)
	{
		//double dist = sqrt(dx*dx + dy * dy);
	}
}

void Shape::update(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double maxY)
{
	updatePos(dt, shapes, maxX, maxY);
}
