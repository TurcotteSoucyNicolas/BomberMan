#include "Destructible.h"

Destructible::Destructible(SDL_Renderer* graphics, Vector2* gridIndex)
{
	m_Destroyed = false;
	m_HaveEnd = false;
	m_GridIndex = gridIndex;
	m_Position = new Vector2(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32);
	m_DestructibleSprite = new Sprite(m_Position, Vector2(32, 32));
	m_DestructibleSprite->LoadTexture(graphics, "assets/Destructible.png");
	m_DoorSprite = new Sprite(m_Position, Vector2(32, 32));
	m_DoorSprite->LoadTexture(graphics, "assets/Trapdoor.png");
}

Destructible::~Destructible()
{
	if (m_DestructibleSprite != nullptr)
	{
		delete (m_DestructibleSprite);
		m_DestructibleSprite = nullptr;
	}
	if (m_Position != nullptr)
	{
		delete(m_Position);
		m_Position = nullptr;
	}
	if (m_DoorSprite != nullptr)
	{
		delete(m_DoorSprite);
		m_DoorSprite = nullptr;
	}
	if (m_GridIndex != nullptr)
	{
		delete(m_GridIndex);
		m_GridIndex = nullptr;
	}
}

void Destructible::Draw(SDL_Renderer* graphics)
{
	if (!m_Destroyed)
	{
		if (m_DestructibleSprite != nullptr)
		{
			m_DestructibleSprite->Draw(graphics);
		}
	}
	else if (m_Destroyed && m_HaveEnd)
	{
		if (m_DoorSprite != nullptr)
		{
			m_DoorSprite->Draw(graphics);
		}
	}
}
