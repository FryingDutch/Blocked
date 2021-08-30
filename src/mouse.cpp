#include "Mouse.h"

namespace Blocked
{
	int Mouse::posX = 0;
	int Mouse::posY = 0;
	const unsigned int Mouse::NUM_OF_BUTTONS = 5;
	KeyButton Mouse::buttons[Mouse::NUM_OF_BUTTONS] = { KeyButton{}, KeyButton{}, KeyButton{}, KeyButton{}, KeyButton{} };

	bool Mouse::wheelUp = false;
	bool Mouse::wheelDown = false;
}