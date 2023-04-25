#include "Input.h"


void Input::CheckInput()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates == nullptr)
	{
		return;
	}
	if (currentKeyStates[SDL_SCANCODE_UP])
	{
		Up = true;
		Down = false;
		Left = false;
		Right = false;
		Space = false;
	}
	else if (currentKeyStates[SDL_SCANCODE_DOWN])
	{
		Up = false;
		Down = true;
		Left = false;
		Right = false;
		Space = false;
	}
	else if (currentKeyStates[SDL_SCANCODE_LEFT])
	{
		Up = false;
		Down = false;
		Left = true;
		Right = false;
		Space = false;
	}
	else if (currentKeyStates[SDL_SCANCODE_RIGHT])
	{
		Up = false;
		Down = false;
		Left = false;
		Right = true;
		Space = false;
	}
	else if (currentKeyStates[SDL_SCANCODE_SPACE])
	{
		Up = false;
		Down = false;
		Left = false;
		Right = false;
		Space = true;
	}
	else
	{
		Up = false;
		Down = false;
		Left = false;
		Right = false;
		Space = false;
		SpaceIsPress = false;
		HaveMove = false;
	}
}
