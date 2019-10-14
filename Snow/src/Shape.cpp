#include "Shape.h"

void Shape::draw(SDL_Surface * surf)
{

}

void Shape::updatePos(double dt)
{
	this->x += vx * dt;
	this->y += vy * dt;
}

void Shape::update(double dt)
{
	updatePos(dt);
}
