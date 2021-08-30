#pragma once
#include <vector>
#include "EventHandler.h"
#include "Renderer.h"
#include "Player.h"
#include "Maps.h"
#include "BlockedGame.h"
#include "Tile.h"
#include "CollisionManager.h"
#include "Vec2.h"
#include "Player.h"

namespace Blocked
{
	class LevelManager
	{
	public:
		static unsigned int level;

	public:
		static Vec2 size;
		static std::vector<Tile> map;
		static std::vector<Tile> backgrounds;
		static std::vector<Tile> walls;

		static Vec2 leftSpawn;
		static Vec2 rightSpawn;

	public:
		static void LoadMap(const std::vector<std::vector<int>>& _map, Vec2 _leftSpawn, Vec2 _rightSpawn);

	public:
		static void drawLevel(Player& _player);

	public:
		enum entering
		{
			LEFT, RIGHT, UP, DOWN
		};
	};
}