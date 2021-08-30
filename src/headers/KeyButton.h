#pragma once

namespace Blocked
{
	struct KeyButton
	{
	public:
		char m_currentState;
		char m_lastState;

	public:
		KeyButton() :
			m_currentState(NEUTRAL), m_lastState(NEUTRAL) {}

	public:
		enum : char
		{
			RELEASED = 'R', PRESSED = 'P', HOLD = 'H', NEUTRAL = 'N'
		};
	};
}