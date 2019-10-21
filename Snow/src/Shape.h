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
	Shape() = default;
	double x = 0, y = 0;
	double vx = 0, vy = 0;
	double size = 0;
	double density = 0;
	double prev_x = 0, prev_y = 0;
	double gravityMult = 1;
	Color c = { 0,0,0 };
	
	bool collisionEnabled = true;
	bool* euthanasiaPlug;
	bool isActive = true; //false disables all the processing for this Shape

	virtual void draw(SDL_Surface* surf);
	void updatePos(double dt);
	virtual void update(double dt);
	virtual void onWallCollision();
	virtual double mass();
	virtual double area();
	double velocity();
	double velocity_squared();
	double energy();
	double momentum();

	void markForDeletion();
	double getLastUpdateGravityVyDelta();
protected:
	double lastUpdateGravityVyDelta = 0; 
};