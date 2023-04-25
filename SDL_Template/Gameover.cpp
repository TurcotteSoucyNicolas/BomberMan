#include "Gameover.h"

Gameover::Gameover(SDL_Renderer* graphics)
	:m_Position(new Vector2(0, 0))
	, m_Seize(Vector2(480, 416))
	, m_Timer(0)
{
	m_MenuBackground = new Sprite(m_Position, m_Seize);
	m_MenuText = new Sprite(m_Position, m_Seize);
	m_MenuBackground->LoadTexture(graphics, "assets/Gameover.png");
	m_MenuText->LoadTexture(graphics, "assets/exit.png");
}

Gameover::~Gameover()
{
	if (m_MenuBackground != nullptr)
	{
		delete(m_MenuBackground);
		m_MenuBackground = nullptr;
	}
	if (m_MenuText != nullptr)
	{
		delete(m_MenuText);
		m_MenuText = nullptr;
	}
	if (m_Position == nullptr)
	{
		delete(m_Position);
		m_Position = nullptr;
	}
}

void Gameover::Draw(SDL_Renderer* graphics)
{
	if (m_Timer % 2 == 0)
	{
		m_MenuBackground->Draw(graphics);
		m_MenuText->Draw(graphics);
	}
	else
	{
		m_MenuBackground->Draw(graphics);
	}

}

void Gameover::Update()
{
	m_Timer = SDL_GetTicks() / 1000;
}

