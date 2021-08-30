#include "Timer.h"

namespace Blocked
{
	void Timer::startTimer()
	{
		if (!this->timerStarted)
		{
			this->current_time = SDL_GetTicks();
			this->timerStarted = true;
		}
	}

	unsigned int Timer::showTimePassed()
	{
		this->time_passed = SDL_GetTicks();
		return this->time_passed - this->current_time;
	}

	bool Timer::ifTimePassed(unsigned int timePassed)
	{
		this->last_time = SDL_GetTicks();
		if (!this->timerStarted)
		{
			this->current_time = SDL_GetTicks();
			this->timerStarted = true;
		}

		if (this->timerStarted && this->last_time >= this->current_time + timePassed)
		{
			timerStarted = false;
			return true;
		}
		return false;
	}

	void Timer::setLoop()
	{
		this->timerStarted = true;
		this->last_time = this->current_time;
		this->current_time = SDL_GetTicks();
		this->time_passed = this->current_time - this->last_time;
	}

	unsigned int Timer::getLoopTime()
	{
		return this->time_passed;
	}
}