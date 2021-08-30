#include "Player.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Gravity.h"
#include "BlockedGame.h"
#include "LevelManager.h"
#include "Window.h"
#include "Camera.h"

namespace Blocked
{
	void Player::m_jump()
	{
		if (this->m_jumping)
		{
			this->m_grounded = false;

			if (!jumpTimer.ifTimePassed(450))
			{
				this->m_direction.y += MovingEntity::UP;
				this->m_speed.y *= 0.980f;
			}

			else
			{
				this->m_jumping = false;
				this->m_falling = false;
				this->m_speed.y = this->m_baseSpeed.y;
			}
		}
	}

	void Player::m_move()
	{
		this->m_lastPosition = this->m_position;

		this->m_direction = MovingEntity::NONE;

		if (Keyboard::keys[Keyboard::D].m_currentState == KeyButton::HOLD) this->m_direction.x += MovingEntity::RIGHT;
		if (Keyboard::keys[Keyboard::A].m_currentState == KeyButton::HOLD) this->m_direction.x += MovingEntity::LEFT;
		if (Keyboard::keys[Keyboard::W].m_currentState == KeyButton::PRESSED && this->m_grounded) this->m_jumping = true;
		if (Keyboard::keys[Keyboard::SPACE].m_currentState == KeyButton::PRESSED) this->m_hookEnabled = true;

		if (Mouse::wheelUp) { this->m_size.y += 3; this->m_position.y -= 3; }
		else if (Mouse::wheelDown) { this->m_size.y -= 3; this->m_position.y += 3; };

		if (this->m_jumping)
		{
			this->m_jump();
		}

		else Gravity::applyGforce(*this);		

		this-> m_velocity = (this->m_direction * this->m_speed) * BlockedGame::deltaTime;
		this->m_position += this->m_velocity;

		if (this->m_position.x > (double)Window::width * 0.55f - (this->m_size.x / 2) && LevelManager::walls[LevelManager::walls.size() - 1].m_position.x + LevelManager::walls[LevelManager::walls.size() - 1].m_size.x > Window::width)
		{
			this->m_position.x = this->m_lastPosition.x;
			Camera::move(*this, Camera::move::RIGHT);
		}

		else if (this->m_position.x < (double)Window::width * 0.45f - (this->m_size.x / 2) && LevelManager::walls[0].m_position.x < 0)
		{
			this->m_position.x = this->m_lastPosition.x;
			Camera::move(*this, Camera::move::LEFT);
		}	

		if (this->m_position.y > (double)Window::height * 0.55f - (this->m_size.x / 2) && LevelManager::walls[LevelManager::walls.size() - 1].m_position.y + LevelManager::walls[LevelManager::walls.size() - 1].m_size.y > Window::height)
		{
			this->m_position.y = this->m_lastPosition.y;
			Camera::move(*this, Camera::move::DOWN);
		}

		else if (this->m_position.y < (double)Window::height * 0.45f - (this->m_size.y / 2) && LevelManager::walls[0].m_position.y < 0)
		{
			this->m_position.y = this->m_lastPosition.y;
			Camera::move(*this, Camera::move::UP);
		}

		
	}
}