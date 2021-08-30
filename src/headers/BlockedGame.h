#pragma once
#include <vector>
#include "Timer.h"

namespace Blocked
{
	class BlockedGame
	{
	public:
		static bool isRunning;
		static int deltaTime;

		static Timer loopTimer;

	private:
		static void init(const char* _title, const int _SCREEN_WIDTH, const int _SCREEN_HEIGHT);
		static void closeGame();

	public:		
		static void gameLoop();		
	};
}