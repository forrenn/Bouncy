#include <iostream>
#include <sdl/sdl.h>
#include <vector>
#include <memory>
#include <chrono>
#include "Circle.h"
#include "Globals.h"
#include <chrono>
#include <algorithm>
#pragma comment(lib, "SDL2.lib")

#undef main

void main()
{
	int benchmarkMode = 0;
	std::cout.precision(15);
	std::cout << "Run benchmark? 1 = yes, 0 = no: ";
	std::cin >> benchmarkMode;

	SCREEN_WIDTH = DEFAULT_SCREEN_WIDTH;
	SCREEN_HEIGHT = DEFAULT_SCREEN_HEIGHT;
	int benchmarkPasses = 1;
	int visibility = 1;
	if (benchmarkMode)
	{
		SCREEN_WIDTH = BENCHMARK_DEFAULT_SCREEN_WIDTH;
		SCREEN_HEIGHT = BENCHMARK_DEFAULT_SCREEN_HEIGHT;
		std::cout << "Benchmark passes: ";
		std::cin >> benchmarkPasses;
		std::cout << "Render to the screen? 1 = yes, 0 = no: ";
		std::cin >> visibility;
	}
	else
	{
		int w = 0, h = 0;
		std::cout << "Enter desired screen width (0 = default value of " << DEFAULT_SCREEN_WIDTH <<"): ";
		std::cin >> w;
		std::cout << "Enter desired screen height (0 = default value of " << DEFAULT_SCREEN_HEIGHT << "): ";
		std::cin >> h;
		SCREEN_WIDTH = (w == 0) ? DEFAULT_SCREEN_WIDTH : w;
		SCREEN_HEIGHT = (h == 0) ? DEFAULT_SCREEN_HEIGHT : h;
	}

	SDL_Window* window = SDL_CreateWindow("Snow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	
	SDL_Event ev;
	double benchmarkFpsAccumulator = 0;
	for (int benchmarkPass = 0; benchmarkPass < benchmarkPasses; ++benchmarkPass)
	{
		SHAPES.clear();
		if (!benchmarkMode)
		{
			for (int i = 0; i < 1000; ++i)
			{
				Circle c;
				c.size = rand() % 19 + 1;
				c.x = c.size + rand() % int(SCREEN_WIDTH - 2 * c.size - 1);
				c.y = c.size + rand() % int(SCREEN_HEIGHT - 2 * c.size - 1);
				c.vx = rand() % 500 - 250;
				c.vy = rand() % 500 - 250;
				c.c.r = rand() % 256;
				c.c.g = rand() % 256;
				c.c.b = rand() % 256;
				c.gravityMult = 0.3 + (1.4*rand() / RAND_MAX);

				SHAPES.push_back(std::make_unique<Circle>(c));
			}
		}
		else
		{
			Circle c(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 200, 0, -100);
			c.c = { 255,255,255 };
			SHAPES.push_back(std::make_unique<Circle>(c));
		}

		double fpsCounterAccumulator = 0;
		uint64_t frameCounter = 0;
		uint64_t lastShownFrameCounter = 0;
		bool running = true;
		auto startTime = std::chrono::high_resolution_clock::now();
		auto applicationStartTime = startTime;
		while (running)
		{
			if (visibility) SDL_FillRect(windowSurface, 0, 0);
			while (SDL_PollEvent(&ev))
			{
				if (ev.type == SDL_QUIT) return;
			}

			auto endTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> dur = endTime - startTime;
			double dt = dur.count();
			startTime = endTime;

			double dtLocal = dt;
			if (benchmarkMode) dtLocal = BENCHMARK_TIME_STEP;
			for (size_t i = 0; i < SHAPES.size(); ++i) //DO NOT change to range-based for. Vector resizing breaks it.
			{
				//ALWAYS use indexed access, because Shape::update can push to SHAPES
				bool remove = false; //maybe refactor into std::vector<uint8_t> (bool won't play nice with euthanasia-like ask for removal) and handle removal post-frame for ease of multithreading?
				SHAPES[i]->euthanasiaPlug = &remove;
				SHAPES[i]->update(dtLocal);
				if (visibility) SHAPES[i]->draw(windowSurface);

				if (remove)
				{
					SHAPES[i].swap(*(SHAPES.end() - 1));
					SHAPES.pop_back();
					--i;
				}
			}

			/*double avg_vy_acc = 0;
			for (auto& it : SHAPES)
				avg_vy_acc += abs(it->vy);
			std::cout << "Avg |vy|: " << avg_vy_acc / SHAPES.size() << "\n";*/

			if (visibility) SDL_UpdateWindowSurface(window);
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

#ifdef RELEASE
			std::sort(SHAPES.begin(), SHAPES.end()); //improves performance BY A LOT (but only in Release builds). Do not remove.
#endif // RELEASE	

			if (benchmarkMode)
			{
				bool foundActive = false;
				for (const auto& it : SHAPES)
				{
					if (it->isActive)
					{
						foundActive = true;
						break;
					}
				}
				running = foundActive;
			}
		}

		auto applicationEndTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> appDur = applicationEndTime - applicationStartTime;
		double runTime = appDur.count();
		double avgFps = frameCounter / runTime;

		std::cout << "Pass " << benchmarkPass+1 << ": Rendered " << frameCounter << " frames in " << runTime << " sec (" << avgFps << " FPS)\n";
		benchmarkFpsAccumulator += avgFps;
	}

	if (benchmarkMode) std::cout << "Average of all passes: " << benchmarkFpsAccumulator / benchmarkPasses << " FPS.\n";
	system("pause");
}