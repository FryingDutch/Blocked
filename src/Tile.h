#pragma once
#include "Entity.h"
#include "Vec2.h"
#include "ColorPanel.h"

namespace Blocked
{
	class Tile : public Entity
	{
	public:
		static Vec2 tileSize;

	public:
		int m_state = 0;

	public:
		Tile() = default;
		Tile(Vec2 _position, int _state);

	public:
		enum
		{
			BACKGRND = 0, WALL
		};
	};
}