#include "Window.h"
#include "Renderer.h"

namespace Blocked
{
	std::string Window::title;
	unsigned int Window::height = NULL;
	unsigned int Window::width = NULL;

	SDL_Window* Window::window = nullptr;

	bool Window::init(std::string _title, const unsigned int _SCREEN_WIDTH, const unsigned int _SCREEN_HEIGHT)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cerr << "Initialisation Failed! Terminating...\n";
			return false;
		}

		Window::title = _title;
		Window::width = _SCREEN_WIDTH;
		Window::height = _SCREEN_HEIGHT;

		Window::window = SDL_CreateWindow(Window::title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Window::width, Window::height, SDL_WINDOW_SHOWN);
		if (Window::window == nullptr)
		{
			std::cerr << "Window Creation Failed! Terminating...\n";
			return false;
		}
		return true;
	}

	void Window::destroyWindow()
	{
		SDL_DestroyWindow(Window::window);
		//for additional window cleaning code if needed in the future
	}
}