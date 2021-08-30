#include "Tile.h"
#include "Window.h"

namespace Blocked
{
	Vec2 Tile::tileSize{ 50, 50 };

	Tile::Tile(Vec2 _position, int _state) :
		Entity(Vec2(tileSize.x, tileSize.y), _position), m_state(_state)
	{
		switch (this->m_state)
		{
		case WALL:
			this->m_color = ColorPanel::wallBlack;
			break;

		case BACKGRND:
			this->m_color = ColorPanel::white;
			break;

		default:
			break;

		}
	}
}