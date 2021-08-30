#pragma once
#include "Entity.h"
#include "Vec2.h"

namespace Blocked
{
	class Gravity
	{
	public:
		static Vec2 gforce;

	public:
		static void setGforce(double _x, double _y)
		{
			gforce = Vec2(_x, _y);
		}

		static void applyGforce(Entity& _entity)
		{
			_entity.m_position += gforce;
		}
	};
}