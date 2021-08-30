#include "ColorPanel.h"
#include <SDL.h>

namespace Blocked
{
	SDL_Color ColorPanel::white = { 255, 255, 255, 255 };
	SDL_Color ColorPanel::black = { 0, 0, 0, 255 };

	SDL_Color ColorPanel::red = { 255, 0, 0, 255 };
	SDL_Color ColorPanel::green = { 0, 255, 0, 255 };
	SDL_Color ColorPanel::blue = { 0, 0, 255, 255 };

	SDL_Color ColorPanel::playerRed = { 209, 35, 35, 255 };
	SDL_Color ColorPanel::wallBlack = { 5, 5, 5, 255 };
}