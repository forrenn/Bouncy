#include "Rectangle.h"
#include "Helpers.h"

void Rectangle::draw(SDL_Surface * surf)
{
	int endX = x + size;
	int endY = y + height;

	for (int _y = y; y <= endY; ++y)
	{
		for (int _x = x; x <= endX; ++x)
		{
			Helpers::setPixel(surf, _x, _y, c.r, c.g, c.b);
		}
	}
}
