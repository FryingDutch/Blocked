#pragma once
#include <SDL.h>
#include "Entity.h"
#include "Vec2.h"
#include "Timer.h"

namespace Blocked
{
	class MovingEntity : public Entity
	{
	public:
		bool m_jumping{ false };
		bool m_falling{ true };
		bool m_grounded{ false };

		Vec2 m_speed;
		Vec2 m_baseSpeed;
		Vec2 m_direction;
		Vec2 m_velocity{ 0, 0 };

		Timer jumpTimer;
		Timer fallTimer;		

	public:
		MovingEntity(Vec2 _size, Vec2 _position, SDL_Color _color) :
			Entity(_size, _position, _color), m_speed(5, 5), m_direction(0,0) 
		{
			m_baseSpeed = m_speed;
		}
		virtual ~MovingEntity() {};

	public:
		virtual void m_move() = 0;

	public:
		enum
		{
			UP = -1, DOWN = 1, RIGHT = 1, LEFT = -1, NONE = 0
		};
	};
}