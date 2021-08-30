#include <iostream>
#include <thread>
#include "BlockedGame.h"
#include "EventHandler.h"
#include "Mouse.h"
#include "Keyboard.h"

namespace Blocked
{
	SDL_Event EventHandler::events;
	const Uint8* EventHandler::keyState = SDL_GetKeyboardState(NULL);

	void EventHandler::mouseAndWindowEvents() 
	{
		Mouse::wheelUp = false;
		Mouse::wheelDown = false;

		for (unsigned int i = 0; i < Mouse::NUM_OF_BUTTONS; i++)
		{
			Mouse::buttons[i].m_lastState = Mouse::buttons[i].m_currentState;
			if (Mouse::buttons[i].m_lastState == KeyButton::RELEASED) Mouse::buttons[i].m_currentState = KeyButton::NEUTRAL;
		}

		while (SDL_PollEvent(&EventHandler::events))
		{
			switch (EventHandler::events.type)
			{
			//mouse
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&Mouse::posX, &Mouse::posY);
				break;

			case SDL_MOUSEWHEEL:
				Mouse::wheelUp = EventHandler::events.wheel.y > 0 ? true : false;
				Mouse::wheelDown = EventHandler::events.wheel.y < 0 ? true : false;
				break;

			case SDL_MOUSEBUTTONDOWN:
				switch (EventHandler::events.button.button)  
				{
				case SDL_BUTTON_LEFT:
					Mouse::buttons[Mouse::LMB].m_currentState = KeyButton::PRESSED;
					break;

				case SDL_BUTTON_RIGHT:
					Mouse::buttons[Mouse::RMB].m_currentState = KeyButton::PRESSED;
					break;

				case SDL_BUTTON_MIDDLE:
					Mouse::buttons[Mouse::MMB].m_currentState = KeyButton::PRESSED;
					break;

				case SDL_BUTTON_X1:
					Mouse::buttons[Mouse::X1].m_currentState = KeyButton::PRESSED;
					break;

				case SDL_BUTTON_X2:
					Mouse::buttons[Mouse::X2].m_currentState = KeyButton::PRESSED;
					break;

				default:
					break;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				switch (EventHandler::events.button.button)
				{
				case SDL_BUTTON_LEFT:
					Mouse::buttons[Mouse::LMB].m_currentState = KeyButton::RELEASED;
					break;

				case SDL_BUTTON_RIGHT:
					Mouse::buttons[Mouse::RMB].m_currentState = KeyButton::RELEASED;
					break;

				case SDL_BUTTON_MIDDLE:
					Mouse::buttons[Mouse::MMB].m_currentState = KeyButton::RELEASED;
					break;

				case SDL_BUTTON_X1:
					Mouse::buttons[Mouse::X1].m_currentState = KeyButton::RELEASED;
					break;

				case SDL_BUTTON_X2:
					Mouse::buttons[Mouse::X2].m_currentState = KeyButton::RELEASED;
					break;

				default:
					break;
				}
				break;

			//Window
			case SDL_WINDOWEVENT:
				switch (EventHandler::events.window.event)
				{
				case SDL_WINDOWEVENT_CLOSE:
					BlockedGame::isRunning = false;
					break;

				default:
					break;
				}
				break;

			default:
				break;
			}
		}

		for (unsigned int i = 0; i < Mouse::NUM_OF_BUTTONS; i++)
		{
			if (Mouse::buttons[i].m_lastState == KeyButton::PRESSED || Mouse::buttons[i].m_lastState == KeyButton::HOLD && Mouse::buttons[i].m_currentState == KeyButton::PRESSED) 
				Mouse::buttons[i].m_currentState = KeyButton::HOLD;
		}
	}

	void EventHandler::keyboardEvents()
	{
		for (unsigned int i = 0; i < Keyboard::NUM_OF_KEYS; i++)
		{
			Keyboard::keys[i].m_lastState = Keyboard::keys[i].m_currentState;
			Keyboard::keys[i].m_currentState = KeyButton::NEUTRAL;
		}

		if (keyState[SDL_SCANCODE_SPACE]) Keyboard::keys[Keyboard::SPACE].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_ESCAPE]) Keyboard::keys[Keyboard::ESCAPE].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_UP]) Keyboard::keys[Keyboard::UP].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_DOWN]) Keyboard::keys[Keyboard::DOWN].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_LEFT]) Keyboard::keys[Keyboard::LEFT].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_RIGHT]) Keyboard::keys[Keyboard::RIGHT].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_W]) Keyboard::keys[Keyboard::W].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_S]) Keyboard::keys[Keyboard::S].m_currentState = KeyButton::PRESSED;		
		if (keyState[SDL_SCANCODE_D]) Keyboard::keys[Keyboard::D].m_currentState = KeyButton::PRESSED;
		if (keyState[SDL_SCANCODE_A]) Keyboard::keys[Keyboard::A].m_currentState = KeyButton::PRESSED;

		for (unsigned int i = 0; i < Keyboard::NUM_OF_KEYS; i++)
		{
			if (Keyboard::keys[i].m_lastState == KeyButton::PRESSED || Keyboard::keys[i].m_lastState == KeyButton::HOLD && Keyboard::keys[i].m_currentState == KeyButton::PRESSED)
				Keyboard::keys[i].m_currentState = KeyButton::HOLD;

			if (Keyboard::keys[i].m_lastState == KeyButton::HOLD && Keyboard::keys[i].m_currentState == KeyButton::NEUTRAL) 
				Keyboard::keys[i].m_currentState = KeyButton::RELEASED;
		}
	}

	void EventHandler::handleAll()
	{
		EventHandler::mouseAndWindowEvents();
		EventHandler::keyboardEvents();
	}
} 