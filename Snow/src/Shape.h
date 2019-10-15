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
	double x = 0, y = 0;
	double vx = 0, vy = 0;
	double size = 0;
	Color c = { 0,0,0 };
	double prev_x = 0, prev_y = 0;
	bool collisionEnabled = true;

	virtual void draw(SDL_Surface* surf);
	void updatePos(double dt);
	virtual void update(double dt);
	virtual void onWallCollision();
};