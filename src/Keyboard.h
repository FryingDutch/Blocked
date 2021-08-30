#pragma once
#include "KeyButton.h"

namespace Blocked
{
	struct Keyboard
	{
	public:
		static const unsigned int NUM_OF_KEYS;
		static KeyButton keys[];

	public:
		enum
		{
			A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, UP, DOWN, LEFT, RIGHT, SPACE, ESCAPE
		};
	};
}