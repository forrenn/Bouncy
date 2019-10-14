#include <iostream>
#include <sdl/sdl.h>
#include <vector>
#include <memory>
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
	shapes.push_back(std::make_unique<Circle>(500, 300, 40, 6, -6));
	while (true)
	{
		SDL_FillRect(windowSurface, 0, 0);
		while (SDL_PollEvent(&ev))
		{

		}
		
		double dt = 0.05;
		for (auto& it : shapes)
		{
			it->update(dt);
			it->draw(windowSurface);
		}
		SDL_UpdateWindowSurface(window);
	}
	
	system("pause");
}