#pragma once
#include <SDL.h>

namespace Blocked
{
	struct EventHandler
	{
	private:
		static SDL_Event events;
		static const Uint8* keyState;

	private:
		static void mouseAndWindowEvents();
		static void keyboardEvents();

	public:
		static void handleAll();
	};
}