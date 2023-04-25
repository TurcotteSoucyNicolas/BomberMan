#pragma once
#include <SDL_timer.h>
class Timer
{
public:
	void UpdateTime();
	float GetTime() { return m_CurrentTime; };

private:
	float m_CurrentTime = 0;
};

