#include "Bomb.h"

Bomb::Bomb(SDL_Renderer* graphics)
	:m_StartTime(0)
	, m_EndTime(0)
	, m_Done(false)
	, m_GridIndex(new Vector2(0, 0))
	, m_IsActive(false)
{
	m_Position = new Vector2(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32);
	m_BombSprite = new Sprite(m_Position, Vector2(32, 32));
	m_BombSprite->LoadTexture(graphics, "assets/Bomb.png");
}

Bomb::~Bomb()
{
	if (m_BombSprite != nullptr)
	{
		delete(m_BombSprite);
		m_BombSprite = nullptr;
	}
	if (m_Position != nullptr)
	{
		delete(m_Position);
		m_Position = nullptr;
	}
	if (m_GridIndex != nullptr)
	{
		delete(m_GridIndex);
		m_GridIndex = nullptr;
	}
}

void Bomb::Update(float currentTime)
{
	if (m_IsActive && currentTime >= m_EndTime)
	{
		m_Done = true;
		m_IsActive = false;
	}
}

void Bomb::SpawnBomb(float currentTime, Vector2 Index)
{
	m_StartTime = currentTime;
	m_EndTime = m_StartTime + 2.5f;
	m_GridIndex->SetVector(Index.GetX(),Index.GetY());
	m_IsActive = true;
}

void Bomb::Draw(SDL_Renderer* graphics)
{
	if (m_IsActive)
	{
		if (m_BombSprite != nullptr)
		{
			m_BombSprite->Draw(graphics);
		}
	}
}
