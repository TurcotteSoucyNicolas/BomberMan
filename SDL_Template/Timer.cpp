#include "Timer.h"
#include <iostream>
void Timer::UpdateTime()
{
	m_CurrentTime = SDL_GetTicks()/1000;
	std::cout << m_CurrentTime;
}
