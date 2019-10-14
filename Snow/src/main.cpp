#include <iostream>
#include <sdl/sdl.h>
#pragma comment(lib, "SDL2.lib")

#undef main

void main()
{
	int w = 1024;
	int h = 600;
	SDL_Window* window = SDL_CreateWindow("Snow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	
	SDL_Event ev;
	while (true)
	{
		while (SDL_PollEvent(&ev))
		{

		}
		
		
		SDL_UpdateWindowSurface(window);
	}
	
	system("pause");
}