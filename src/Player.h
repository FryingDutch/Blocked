#pragma once
#include "MovingEntity.h"
#include <SDL.h>
#include "Vec2.h"


namespace Blocked
{
	class Player : public MovingEntity
	{
	private:
		bool m_hookEnabled{ false };
	public:
		Player(Vec2 _size, Vec2 _position, SDL_Color _color) :
			MovingEntity(_size, _position, _color)	{}

		Player() = default;

		void m_move() override;
		void m_jump();
		void m_hook();
	};
}