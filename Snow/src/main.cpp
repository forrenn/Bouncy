#include <iostream>
#include <sdl/sdl.h>
#include <vector>
#include <memory>
#include <chrono>
#include "Circle.h"
#include "Globals.h"
#pragma comment(lib, "SDL2.lib")

#undef main

void main()
{
	SCREEN_WIDTH = 1280;
	SCREEN_HEIGHT = 720;
	SDL_Window* window = SDL_CreateWindow("Snow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	
	SDL_Event ev;

	for (int i = 0; i < 1000; ++i)
	{
		double size = rand() % 19 + 1;
		double x = size+rand() % int(SCREEN_WIDTH - 2*size - 1);
		double y = size+rand() % int(SCREEN_HEIGHT - 2*size - 1);
		double vx = rand() % 500 - 250;
		double vy = rand() % 500 - 250;

		SHAPES.push_back(std::make_unique<Circle>(x, y, size, vx, vy));
	}

	/*Circle c(w / 2, h / 2, 20, 0, -100);
	//c.collisionEnabled = false;
	c.c = { 255,255,255 };
	shapes.push_back(std::make_unique<Circle>(c));*/
	
	auto startTime = std::chrono::high_resolution_clock::now();
	while (true)
	{
		SDL_FillRect(windowSurface, 0, 0);
		while (SDL_PollEvent(&ev))
		{

		}
		
		auto endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> dur = endTime - startTime;
		double dt = dur.count();
		startTime = endTime;

		for (size_t i = 0; i < SHAPES.size(); ++i)
		{
			SHAPES[i]->update(dt);
			SHAPES[i]->draw(windowSurface);
		}
		SDL_UpdateWindowSurface(window);
	}
	
	system("pause");
}