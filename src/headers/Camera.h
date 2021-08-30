#pragma once
#include <vector>
#include "LevelManager.h"
#include "BlockedGame.h"

namespace Blocked
{
	struct Camera
	{
	public:
		enum move
		{
			RIGHT, LEFT, UP, DOWN
		};

	public:
		static void move(Player& _player, int _direction) 
		{
			switch(_direction)
			{
			case RIGHT:
				for (unsigned int i = 0; i < LevelManager::walls.size(); i++)
				{
					LevelManager::walls[i].m_position.x -= _player.m_speed.x * BlockedGame::deltaTime;
				}

				for (unsigned int i = 0; i < LevelManager::backgrounds.size(); i++)
				{
					LevelManager::backgrounds[i].m_position.x -= _player.m_speed.x * BlockedGame::deltaTime;
				}
				break;
			

			case LEFT:			
				for (unsigned int i = 0; i < LevelManager::walls.size(); i++)
				{
					LevelManager::walls[i].m_position.x += _player.m_speed.x * BlockedGame::deltaTime;
				}

				for (unsigned int i = 0; i < LevelManager::backgrounds.size(); i++)
				{
					LevelManager::backgrounds[i].m_position.x += _player.m_speed.x * BlockedGame::deltaTime;
				}
				break;

			case UP:
				for (unsigned int i = 0; i < LevelManager::walls.size(); i++)
				{
					LevelManager::walls[i].m_position.y += _player.m_speed.y * BlockedGame::deltaTime;
				}

				for (unsigned int i = 0; i < LevelManager::backgrounds.size(); i++)
				{
					LevelManager::backgrounds[i].m_position.y += _player.m_speed.y * BlockedGame::deltaTime;
				}
				break;

			case DOWN:
				for (unsigned int i = 0; i < LevelManager::walls.size(); i++)
				{
					LevelManager::walls[i].m_position.y -= _player.m_speed.y * BlockedGame::deltaTime;
				}

				for (unsigned int i = 0; i < LevelManager::backgrounds.size(); i++)
				{
					LevelManager::backgrounds[i].m_position.y -= _player.m_speed.y * BlockedGame::deltaTime;
				}
				break;

			default:
				break;
			}
		};
	};
}