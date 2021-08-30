#pragma once
#include "KeyButton.h"

namespace Blocked
{
	struct Mouse
	{
	public:
		static int posX, posY;
		static const unsigned int NUM_OF_BUTTONS;
		static bool wheelUp, wheelDown;

		static KeyButton buttons[];

	public:
		enum
		{
			LMB = 0, RMB, MMB, X1, X2
		};
	};
}