#pragma once
#include <SDL.h>
#include <vector>
#include "Window.h"
#include "Entity.h"
#include "Tile.h"

namespace Blocked
{
	struct Renderer
	{
	public:
		static SDL_Renderer* renderer;

	public:
		static bool init();
		static void drawEntity(Entity& _gameObject);
		static void drawEntityVector(std::vector<Entity>& _gameObjects);
		static void drawTiles(std::vector<Tile>& _tiles);
		static void destroyRenderer();
	};
}