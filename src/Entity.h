#pragma once
#include <iostream>
#include <SDL.h>
#include "Vec2.h"

namespace Blocked
{
	class Entity : public SDL_Rect
	{
	public:
		Vec2 m_size{ 100, 100 };
		Vec2 m_position{ 100, 100 };
		Vec2 m_lastPosition = m_position;
		SDL_Color m_color = { 0, 0, 0 ,0 };

	public:
		Entity(Vec2 _size, Vec2 _position, SDL_Color _color) :
			m_size(_size), m_position(_position), m_color(_color){
		}

		Entity(Vec2 _size, Vec2 _position) :
			m_size(_size), m_position(_position){
		};

		virtual ~Entity() {};
	};
}