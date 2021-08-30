#include "Keyboard.h"

namespace Blocked
{
	const unsigned int Keyboard::NUM_OF_KEYS = 32U;
	KeyButton Keyboard::keys[Keyboard::NUM_OF_KEYS] =
	{
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}, KeyButton{},
		KeyButton{}, KeyButton{}
	};
}