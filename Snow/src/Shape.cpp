#include "Shape.h"
#include <algorithm>
#include "Globals.h"
void Shape::draw(SDL_Surface * surf)
{

}

void Shape::updatePos(double dt)
{
	if (!isActive) return;

	/*if ((abs(vx) + abs(vy)) < SPEED_CUTOFF && (abs(y)+abs(size)) < 1)
	{
		this->isActive = false;
		vx = 0;
		vy = 0;
	}*/

	lastUpdateGravityVyDelta = GRAVITY * dt;
	vy += lastUpdateGravityVyDelta; //gravity
	double xCopy = x;
	double yCopy = y;
	this->x += vx * dt;
	this->y += vy * dt;
	if (x + size > SCREEN_WIDTH || x - size < 0)
	{
		vx = -vx;
		x = prev_x;
		onWallCollision();
	}
	else prev_x = xCopy;
	
	if (y + size > SCREEN_HEIGHT || y - size < 0)
	{
		vy = -vy;
		y = prev_y;
		onWallCollision();
	}
	else prev_y = yCopy;
	
	/*for (size_t i = 0; i < SHAPES.size(); ++i) //Circle-Circle collision, please refactor in the future (move to Circle)
	{
		if (this == SHAPES[i].get()) continue; //skip self collision
		double dx = SHAPES[i]->x - x;
		double dy = SHAPES[i]->y - y;
		double dist2 = dx * dx + dy * dy;
		double r_sum = size + SHAPES[i]->size;
		r_sum *= r_sum;
		if (dist2 <= r_sum)
		{
			vx = -vx;
			vy = -vy;
			SHAPES[i]->vx = -SHAPES[i]->vx;
			SHAPES[i]->vy = -SHAPES[i]->vy;
		}
	}*/
}

void Shape::update(double dt)
{
	updatePos(dt);
}

void Shape::onWallCollision()
{
}

double Shape::mass()
{
	return density * area();
}

double Shape::area()
{
	return 0.0;
}

double Shape::velocity()
{
	return sqrt(velocity_squared());
}

double Shape::velocity_squared()
{
	return vx * vx + vy * vy;
}

double Shape::energy()
{
	return mass()*velocity_squared(); //*0.5 omitted on purpose - there's no need for it
}

double Shape::momentum()
{
	return mass()*velocity();
}

void Shape::markForDeletion()
{
	*euthanasiaPlug = true;
}
