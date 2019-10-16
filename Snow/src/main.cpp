#include <iostream>
#include <sdl/sdl.h>
#include <vector>
#include <memory>
#include <chrono>
#include "Circle.h"
#include "Globals.h"
#include <chrono>
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

	/*Circle c(SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2, 200, 0, -100);
	c.c = { 255,255,255 };
	SHAPES.push_back(std::make_unique<Circle>(c));*/
	
	auto startTime = std::chrono::high_resolution_clock::now();
	double fpsCounterAccumulator = 0;
	uint64_t frameCounter = 0;
	uint64_t lastShownFrameCounter = 0;
	while (true)
	{
		SDL_FillRect(windowSurface, 0, 0);
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT) return;
		}
		
		auto endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> dur = endTime - startTime;
		double dt = dur.count();
		startTime = endTime;

		for (size_t i = 0; i < SHAPES.size(); ++i) //DO NOT change to range-based for. Vector resizing breaks it.
		{
			//ALWAYS use indexed access, because Shape::update can push to SHAPES
			bool remove = false;
			SHAPES[i]->euthanasiaPlug = &remove;
			SHAPES[i]->update(dt);
			SHAPES[i]->draw(windowSurface);

			if (remove)
			{
				SHAPES[i].swap(*(SHAPES.end() - 1));
				SHAPES.pop_back();
				--i;
			}
		}
		
		SDL_UpdateWindowSurface(window);
		++frameCounter;
		fpsCounterAccumulator += dt;
		if (fpsCounterAccumulator >= FPS_COUNTER_REFRESH_INTERVAL)
		{
			uint64_t frames = frameCounter - lastShownFrameCounter;
			lastShownFrameCounter = frameCounter;
			double fps = frames / fpsCounterAccumulator;
			fpsCounterAccumulator = 0;

			std::cout << fps << " FPS" << "\n";
		}
		
	}
	
	system("pause");
}