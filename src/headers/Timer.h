#pragma once
#include <SDL.h>

namespace Blocked
{
	class Timer
	{
	private:
		unsigned int current_time = NULL;
		unsigned int time_passed = NULL;
		unsigned int last_time = NULL;

	public:
		bool timerStarted = false;

	public:
		Timer() = default;
		~Timer() = default;		

		void startTimer();
		unsigned int showTimePassed();
		bool ifTimePassed(unsigned int timePassed);

		void setLoop();
		unsigned int getLoopTime();
	};
}