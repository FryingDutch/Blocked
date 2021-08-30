#include <SDL.h>
#include "Window.h"
#include "Renderer.h"
#include "Entity.h"
#include "Tile.h"
#include "Vec2.h"

namespace Blocked
{
	SDL_Renderer* Renderer::renderer = nullptr;

	bool Renderer::init()
	{
		Renderer::renderer = SDL_CreateRenderer(Window::window, -1, SDL_RENDERER_PRESENTVSYNC);
		if (Renderer::renderer == nullptr)
		{
			std::cout << "Renderer Creation Failure! Terminating...\n";
			return false;
		}

		Tile::tileSize = Vec2{ (double)Window::width / 10, (double)Window::height / 10 };

		return true;
	}

	void Renderer::drawEntity(Entity& _gameObject)
	{
		SDL_SetRenderDrawColor(renderer, _gameObject.m_color.r, _gameObject.m_color.g, _gameObject.m_color.b, _gameObject.m_color.a);
		SDL_Rect _rect{ (int)_gameObject.m_position.x, (int)_gameObject.m_position.y, (int)_gameObject.m_size.x, (int)_gameObject.m_size.y};
		SDL_RenderFillRect(renderer, &_rect);
	}

	void Renderer::drawEntityVector(std::vector<Entity>& _gameObjects)
	{
		for (unsigned int i = 0; i < _gameObjects.size(); i++)
		{
			Renderer::drawEntity(_gameObjects[i]);
		}
	}

	void Renderer::drawTiles(std::vector<Tile>& _tiles)
	{
		for (unsigned int i = 0; i < _tiles.size(); i++)
		{
			Renderer::drawEntity(_tiles[i]);
		}
	}

	void Renderer::destroyRenderer()
	{
		SDL_DestroyRenderer(Renderer::renderer);
		//for additional renderer cleaning code if needed in the future
	}
}