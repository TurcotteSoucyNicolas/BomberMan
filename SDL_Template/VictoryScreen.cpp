#include "VictoryScreen.h"

VictoryScreen::VictoryScreen(SDL_Renderer* graphics)
{
	Timer = 0;
	m_Position = new Vector2(0, 0);
	m_Seize = Vector2(480, 416);
	m_SpriteBackground = new Sprite(m_Position, m_Seize);
	m_SpriteText = new Sprite(m_Position, m_Seize);
	m_SpriteBackground->LoadTexture(graphics, "assets/Victory.png");
	m_SpriteText->LoadTexture(graphics, "assets/exit.png");
}

VictoryScreen::~VictoryScreen()
{
	if (m_Position != nullptr)
	{
		delete(m_Position);
		m_Position = nullptr;
	}
	if (m_SpriteBackground != nullptr)
	{
		delete(m_SpriteBackground);
		m_SpriteBackground = nullptr;
	}
	if (m_SpriteText != nullptr)
	{
		delete(m_SpriteText);
		m_SpriteText = nullptr;
	}
}

void VictoryScreen::Update()
{
	Timer = SDL_GetTicks() / 1000;
}

void VictoryScreen::Draw(SDL_Renderer* graphics)
{
	if (Timer % 2 == 0)
	{
		m_SpriteBackground->Draw(graphics);
		m_SpriteText->Draw(graphics);
	}
	else
	{
		m_SpriteBackground->Draw(graphics);
	}
}
