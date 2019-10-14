#include "Shape.h"

void Shape::draw(SDL_Surface * surf)
{

}

void Shape::updatePos(double dt, std::vector<std::unique_ptr<Shape>>& shapes)
{
	this->x += vx * dt;
	this->y += vy * dt;
}

void Shape::update(double dt, std::vector<std::unique_ptr<Shape>>& shapes)
{
	updatePos(dt, shapes);
}
