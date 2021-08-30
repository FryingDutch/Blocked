#pragma once
#include <iostream>
#include <SDL.h>
#include <string>

namespace Blocked
{
	struct Window
	{
	public:
		static std::string title;
		static unsigned int height, width;
		static bool isRunning;

	public:
		static SDL_Window* window;

	public:
		static bool init(std::string _title, unsigned int _width, unsigned int _height);
		static void destroyWindow();
	};
}