#include <iostream>
#include <sdl/sdl.h>
#include <vector>
#include <memory>
#include <chrono>
#include "Circle.h"
#pragma comment(lib, "SDL2.lib")

#undef main

void main()
{
	int w = 1024;
	int h = 600;
	SDL_Window* window = SDL_CreateWindow("Snow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	
	SDL_Event ev;
	std::vector<std::unique_ptr<Shape>> shapes;
	//shapes.reserve(100*1000*1000);
	for (int i = 0; i < 1000; ++i)
	{
		double size = rand() % 19 + 1;
		double x = size+rand() % int(w - 2*size - 1);
		double y = size+rand() % int(h - 2*size - 1);
		double vx = rand() % 500 - 250;
		double vy = rand() % 500 - 250;

		shapes.push_back(std::make_unique<Circle>(x, y, size, vx, vy));
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

		for (size_t i = 0; i < shapes.size(); ++i)
		{
			shapes[i]->update(dt, shapes, w, h);
			shapes[i]->draw(windowSurface);
		}
		SDL_UpdateWindowSurface(window);
	}
	
	system("pause");
}