#pragma once
#include <SDL.h>

namespace Blocked
{
	struct ColorPanel
	{
	public:
		static SDL_Color white;
		static SDL_Color black;

		static SDL_Color green;
		static SDL_Color red;
		static SDL_Color blue;

		static SDL_Color playerRed;
		static SDL_Color wallBlack;
	};
}