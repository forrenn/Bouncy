#include "Shape.h"
#include <algorithm>
void Shape::draw(SDL_Surface * surf)
{

}

void Shape::updatePos(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double maxY)
{
	vy += 9.81*dt; //gravity
	double xCopy = x;
	double yCopy = y;
	this->x += vx * dt;
	this->y += vy * dt;
	if (x + size > maxX || x - size < 0)
	{
		vx = -vx;
		x = prev_x;
	}
	else prev_x = xCopy;
	
	if (y + size > maxY || y - size < 0)
	{
		vy = -vy;
		y = prev_y;
	}
	else prev_y = yCopy;

	for (size_t i = 0; i < shapes.size(); ++i) //Circle-Circle collision, please refactor in the future (move to Circle)
	{
		if (this == shapes[i].get()) continue; //skip self collision
		double dx = shapes[i]->x - x;
		double dy = shapes[i]->y - y;
		double dist = sqrt(dx*dx + dy * dy);
		double r_sum = size + shapes[i]->size;
		if (dist <= r_sum)
		{
			vx = -vx;
			vy = -vy;
			shapes[i]->vx = -shapes[i]->vx;
			shapes[i]->vy = -shapes[i]->vy;
		}
	}
}

void Shape::update(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double maxY)
{
	updatePos(dt, shapes, maxX, maxY);
}
