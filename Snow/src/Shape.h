#pragma once
#include <SDL/SDL.h>
#include <vector>
#include <memory>

struct Color
{
	uint8_t r, g, b;
};

struct Shape
{
	double x, y;
	double vx, vy;
	double size;
	Color c;
	double prev_x, prev_y;
	
	virtual void draw(SDL_Surface* surf);
	void updatePos(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double maxY);
	virtual void update(double dt, std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double max);
	virtual void onWallCollision(std::vector<std::unique_ptr<Shape>>& shapes, double maxX, double max);
};