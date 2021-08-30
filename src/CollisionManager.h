#pragma once
#include <vector>
#include "Entity.h"
#include "MovingEntity.h"

namespace Blocked
{
	struct CollisionManager
	{
		template<typename T, typename N>
		static void doCheck(std::vector<T>& _entitys, N& _movingEntity)
		{
			_movingEntity.h = _movingEntity.m_size.y;
			_movingEntity.w = _movingEntity.m_size.x;
			double entLeft = _movingEntity.x = _movingEntity.m_position.x;
			double entTop = _movingEntity.y = _movingEntity.m_position.y;

			double entRight = (double)_movingEntity.x + _movingEntity.w;
			double entBottom = (double)_movingEntity.y + _movingEntity.h;

			for (unsigned int i = 0; i < _entitys.size(); i++)
			{
				_entitys[i].h = (int)_entitys[i].m_size.y;
				_entitys[i].w = (int)_entitys[i].m_size.x;
				double secLeft = _entitys[i].x = _entitys[i].m_position.x;
				double secTop = _entitys[i].y = _entitys[i].m_position.y;
				
				double secRight = (double)_entitys[i].x + _entitys[i].w;
				double secBottom = (double)_entitys[i].y + _entitys[i].h;

				//MovingEntity bottom side vs other topside
				if (entBottom > secTop && entBottom < secTop + (_movingEntity.m_speed.y * BlockedGame::deltaTime) + 1 && entTop < secTop && entRight > secLeft + (_movingEntity.m_speed.x + 1) && entLeft < secRight - (_movingEntity.m_speed.x))
				{
					_movingEntity.m_position.y = _entitys[i].m_position.y - _movingEntity.m_size.y;
					_movingEntity.m_jumping = false;
					_movingEntity.m_falling = false;
					_movingEntity.m_grounded = true;
				}

				//MovingEntity top side vs other downside
				else if (entTop < secBottom && entTop > secBottom - (_movingEntity.m_speed.y * BlockedGame::deltaTime) - 1 && entBottom > secBottom && entRight > secLeft + (_movingEntity.m_speed.x + 1) && entLeft < secRight - (_movingEntity.m_speed.x + 1))
				{
					_movingEntity.m_position.y = _entitys[i].m_position.y + _entitys[i].m_size.y;
					_movingEntity.m_jumping = false;
					_movingEntity.m_falling = true;
					_movingEntity.m_grounded = false;

					_movingEntity.jumpTimer.timerStarted = false;
					_movingEntity.m_speed.y = _movingEntity.m_baseSpeed.y;
				}

				//MovingEntity right side vs other leftside
				else if (entRight > secLeft && entRight < secLeft + (_movingEntity.m_speed.x * BlockedGame::deltaTime) + 1 && entLeft < secLeft && entBottom > secTop && entTop < secBottom)
				{
					_movingEntity.m_position.x = _entitys[i].m_position.x - _movingEntity.m_size.x;
				}

				//MovingEntity left side vs other rightside
				else if (entLeft < secRight && entLeft > secRight - (_movingEntity.m_speed.x * BlockedGame::deltaTime) - 1 && entRight > secRight && entBottom > secTop && entTop < secBottom)
				{
					_movingEntity.m_position.x = _entitys[i].m_position.x + _entitys[i].m_size.x;
				}
			}
		};
	};
}