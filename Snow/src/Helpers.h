#pragma once
#include <SDL/SDL.h>
namespace Helpers
{
	static void setPixel(SDL_Surface* s, int x, int y, uint32_t r, uint32_t g, uint32_t b)
	{
		SDL_PixelFormat* format = s->format;
		Uint32 color = 0;
		color |= b << format->Bshift;
		color |= g << format->Gshift;
		color |= r << format->Rshift;

		char* px = (char*)s->pixels + s->pitch*y + x * format->BytesPerPixel;
		*(Uint32*)px = color;
	}
}