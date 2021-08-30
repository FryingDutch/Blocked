#pragma once

namespace Blocked
{
	struct Vec2
	{
	public:
		double x, y;

	public:
		Vec2() = default;
		Vec2(double _x, double _y) :
			x(_x), y(_y) {}

		Vec2 operator+(const Vec2& rhs)
		{
			return Vec2(this->x + rhs.x, this->y + rhs.y);
		}

		Vec2 operator+=(const Vec2& rhs)
		{
			return Vec2(this->x += rhs.x, this->y += rhs.y);
		}

		Vec2 operator-(const Vec2& rhs)
		{
			return Vec2(this->x - rhs.x, this->y - rhs.y);
		}

		Vec2 operator-=(const Vec2& rhs)
		{
			return Vec2(this->x -= rhs.x, this->y -= rhs.y);
		}

		Vec2 operator*(const Vec2& rhs)
		{
			return Vec2(this->x * rhs.x, this->y * rhs.y);
		}

		Vec2 operator*=(const Vec2& rhs)
		{
			return Vec2(this->x *= rhs.x, this->y *= rhs.y);
		}

		Vec2 operator/(const Vec2& rhs)
		{
			return Vec2(this->x / rhs.x, this->y / rhs.y);
		}

		Vec2 operator/=(const Vec2& rhs)
		{
			return Vec2(this->x /= rhs.x, this->y /= rhs.y);
		}

		Vec2 operator=(const int& rhs)
		{
			return Vec2(this->x = rhs, this->y = rhs);
		}

		Vec2 operator*(const int& rhs)
		{
			return Vec2(this->x * rhs, this->y * rhs);
		}

		Vec2 operator*=(const int& rhs)
		{
			return Vec2(this->x *= rhs, this->y *= rhs);
		}

		bool operator==(const Vec2& rhs)
		{
			if (this->x == rhs.x && this->y == rhs.y) return true;
			return false;
		}

		bool operator!=(const Vec2& rhs)
		{
			if (this->x != rhs.x || this->y != rhs.y) return true;
			return false;
		}
	};
}