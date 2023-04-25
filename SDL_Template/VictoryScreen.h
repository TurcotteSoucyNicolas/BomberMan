#pragma once
#include "Sprite.h"
class VictoryScreen
{
public:
	VictoryScreen(SDL_Renderer* graphics);
	~VictoryScreen();
	void Update();
	void Draw(SDL_Renderer* graphics);
private:
	Vector2* m_Position;
	Vector2 m_Seize;
	Sprite* m_SpriteBackground;
	Sprite* m_SpriteText;
	int Timer;
};

