#include <vector>
#include "LevelManager.h"
#include "Player.h"
#include "Tile.h"
#include "Vec2.h"
#include "Camera.h"
#include "Keyboard.h"
#include "Gravity.h"

namespace Blocked
{
	unsigned int LevelManager::level{ 1 };

	Vec2 LevelManager::size;
	std::vector<Tile> LevelManager::map;
	std::vector<Tile> LevelManager::backgrounds;
	std::vector<Tile> LevelManager::walls;

	Vec2 LevelManager::leftSpawn;
	Vec2 LevelManager::rightSpawn;

	void LevelManager::LoadMap(const std::vector<std::vector<int>>& _map, Vec2 _leftSpawn, Vec2 _rightSpawn)
	{
		LevelManager::leftSpawn = _leftSpawn;
		LevelManager::rightSpawn = _rightSpawn;

		LevelManager::size.x = _map[0].size() * Tile::tileSize.x;
		LevelManager::size.y = _map.size() * Tile::tileSize.y;

		bool stillWall{ true };
		for (unsigned int row = 0; row < _map.size(); row++)
		{
			for (unsigned int col = 0; col < _map[row].size(); col++)
			{
				Tile newTile(Vec2((double)col * Tile::tileSize.x, (double)row * Tile::tileSize.y), _map[row][col]);
				int startingCol = col;

				switch (_map[row][col])
				{
				case Tile::BACKGRND:
					LevelManager::backgrounds.push_back(newTile);
					break;

				case Tile::WALL:
					stillWall = true;
					newTile.m_size.x = Tile::tileSize.x;
					while (stillWall && col + 1 < _map[row].size())
					{
						if (_map[row][col + 1] == Tile::WALL)
						{
							newTile.m_size.x += Tile::tileSize.x;
							col++;
						}
						else if (_map[row][col + 1] == Tile::BACKGRND)
						{
							newTile.m_position.x = startingCol * Tile::tileSize.x;
							newTile.m_position.y = row * Tile::tileSize.y;
							stillWall = false;
						}
					}

					LevelManager::walls.push_back(newTile);
					break;

				default:
					break;
				}
			}
		}
	}

	//apply all the generic rules of the game and draw the current scene
	void LevelManager::drawLevel(Player& _player)
	{
		static bool firstFrame{ true };
		static int enteringFrom = NULL;

		if (firstFrame)
		{
			map.clear();
			walls.clear();
			backgrounds.clear();
			
			switch (LevelManager::level)
			{
			case 1:
				LoadMap(Maps::TUT_1, Vec2{ (double)Window::width / 2, 100 }, Vec2{ Window::width - (_player.m_size.x * 0.1f), (Tile::tileSize.y * 5) - _player.m_size.y });
				break;

			case 2:
				LoadMap(Maps::MAP_1, Vec2{ (double)0 - _player.m_size.x * 0.9f, (Tile::tileSize.y * 5) - _player.m_size.y }, Vec2{ LevelManager::size.x - (_player.m_size.x * 0.1f), (Tile::tileSize.y * 3) - _player.m_size.y });
				break;

			case 3:
				LoadMap(Maps::MAP_2, Vec2{ (double)0 - _player.m_size.x * 0.9f, (Tile::tileSize.y * 3) - _player.m_size.y }, Vec2{ Window::width - (_player.m_size.x * 0.1f), (Tile::tileSize.y * 5) - _player.m_size.y });
				break;

			case 4:
				LoadMap(Maps::MAP_3, Vec2{ (double)0 - _player.m_size.x * 0.9f, (Tile::tileSize.y * 5) - _player.m_size.y }, Vec2{ Window::width - (_player.m_size.x * 0.1f), (Tile::tileSize.y * 5) - _player.m_size.y });
				break;

			default:
				BlockedGame::isRunning = false;
				break;
			}

			if(enteringFrom == LevelManager::entering::LEFT) _player.m_position = LevelManager::leftSpawn;
			else if (enteringFrom == LevelManager::entering::RIGHT)
			{
				_player.m_position = LevelManager::rightSpawn;
				while (LevelManager::walls[LevelManager::walls.size() - 1].m_position.x + LevelManager::walls[LevelManager::walls.size() - 1].m_size.x > Window::width)
				{
					Camera::move(_player, Camera::move::RIGHT);
				}
			}

			firstFrame = false;
		}

		EventHandler::handleAll();	
		_player.m_move();

		CollisionManager::doCheck(walls, _player);
		Renderer::drawTiles(LevelManager::walls);
		Renderer::drawTiles(LevelManager::backgrounds);
		Renderer::drawEntity(_player);

		if (_player.m_position.x > Window::width)
		{
			enteringFrom = LevelManager::entering::LEFT;
			LevelManager::level++;
			firstFrame = true;
		}

		else if (_player.m_position.x < (double)0 - _player.m_size.x * 0.9f)
		{
			enteringFrom = LevelManager::entering::RIGHT;
			LevelManager::level--;
			firstFrame = true;
		}

		SDL_RenderPresent(Renderer::renderer);
	}
}