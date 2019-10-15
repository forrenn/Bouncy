#include "Circle.h"
#include "Helpers.h"
#include "Rectangle.h"
#include <memory>
#include <algorithm>
#include "Globals.h"

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

void Circle::onWallCollision()
{
	vx *= 0.7;
	vy *= 0.7;
	if (collisionEnabled)
	{
		/*Rectangle piece;
		piece.x = x;
		piece.y = y;
		piece.prev_x = prev_x;
		piece.prev_y = prev_y;
		piece.c = c;
		piece.collisionEnabled = false;
		piece.size = 5;
		piece.height = 5;

		double piecesToCreate = (abs(vx) + abs(vy)) / 100;
		uint64_t piecesTrunc = std::min(size*size, piecesToCreate);

		for (uint64_t i = 0; i < piecesTrunc; ++i)
		{
			double angle = rand() / double(RAND_MAX) * 2 * M_PI;
			double x_mult = cos(angle);
			double y_mult = sin(angle);
			piece.vx = vx * x_mult;
			piece.vy = vy * y_mult;
			shapes.push_back(std::make_unique<Rectangle>(piece));
		}

		size -= sqrt(piecesTrunc);*/

		Circle child(prev_x, prev_y, size, vx, vy);
		if (size < 1) return;
		size /= 2;
		child.size = size;
		//child.collisionEnabled = false;
	
		child.prev_x = prev_x;
		child.prev_y = prev_y;
		double totalSpeed = sqrt(vx*vx + vy * vy);
		for (int i = 0; i < 4; ++i)
		{
			double angle = rand() / double(RAND_MAX) * 2 * M_PI;
			double x_mult = cos(angle);
			double y_mult = sin(angle);
			child.vx = totalSpeed * x_mult;
			child.vy = totalSpeed * y_mult;
			child.c.r = c.r - i*size;
			child.c.g = c.g - i*size;
			child.c.b = c.b - i*size;

			SHAPES.push_back(std::make_shared<Circle>(child));
		}
		this->size = 0;
		collisionEnabled = false;
	}
}
