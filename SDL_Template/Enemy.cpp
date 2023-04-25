#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* graphics, Vector2* gridIndex)
{
	srand((unsigned)time(NULL));
	m_MoveDelay = 0;
	m_TimeLastMove = 0;
	m_TimeNextMove = 0;
	m_HaveMove = true;
	m_IsAlive = true;
	m_SpriteToShow = DOWN;
	m_GridIndex = gridIndex;
	
	m_Position = new Vector2(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32);
	m_EnemySpriteDown = new Sprite(m_Position, Vector2(32, 32));
	m_EnemySpriteUp = new Sprite(m_Position, Vector2(32, 32));
	m_EnemySpriteLeft = new Sprite(m_Position, Vector2(32, 32));
	m_EnemySpriteRight = new Sprite(m_Position, Vector2(32, 32));
	m_EnemySpriteDown->LoadTexture(graphics, "assets/GreenSoldierFront.png");
	m_EnemySpriteUp->LoadTexture(graphics, "assets/GreenSoldierUp.png");
	m_EnemySpriteLeft->LoadTexture(graphics, "assets/GreenSoldierLeft.png");
	m_EnemySpriteRight->LoadTexture(graphics, "assets/GreenSoldierRight.png");
}

Enemy::~Enemy()
{
	if (m_EnemySpriteDown != nullptr)
	{
		delete(m_EnemySpriteDown);
		m_EnemySpriteDown = nullptr;
	}
	if (m_EnemySpriteUp != nullptr)
	{
		delete(m_EnemySpriteUp);
		m_EnemySpriteUp = nullptr;
	}
	if (m_EnemySpriteLeft != nullptr)
	{
		delete(m_EnemySpriteLeft);
		m_EnemySpriteLeft = nullptr;
	}
	if (m_EnemySpriteRight != nullptr)
	{
		delete(m_EnemySpriteRight);
		m_EnemySpriteRight = nullptr;
	}
	if (m_GridIndex != nullptr)
	{
		delete(m_GridIndex);
		m_GridIndex = nullptr;
	}
	if (m_Position != nullptr)
	{
		delete(m_Position);
		m_Position = nullptr;
	}
}

bool Enemy::HaveToMove(float currentTime)
{
	if (!m_IsAlive)
	{
		return false;
	}
	if (currentTime < m_TimeNextMove)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Enemy::Draw(SDL_Renderer* graphics)
{
	if (!m_IsAlive)
	{
		return;
	}
	if (m_SpriteToShow == UP)
	{
		if (m_EnemySpriteUp != nullptr)
		{
			m_EnemySpriteUp->Draw(graphics);
		}
	}
	else if (m_SpriteToShow == DOWN)
	{
		if (m_EnemySpriteDown != nullptr)
		{
			m_EnemySpriteDown->Draw(graphics);
		}
	}
	else if (m_SpriteToShow == LEFT)
	{
		if (m_EnemySpriteLeft != nullptr)
		{
			m_EnemySpriteLeft->Draw(graphics);
		}
	}
	else if (m_SpriteToShow == RIGHT)
	{
		if (m_EnemySpriteRight != nullptr)
		{
			m_EnemySpriteRight->Draw(graphics);
		}
	}
}

void Enemy::Update(float currentTime)
{
	if (!m_IsAlive)
	{
		return;
	}
	if (m_HaveMove)
	{
		m_TimeLastMove = currentTime;
		m_MoveDelay = rand() % 3 + 1;
		m_TimeNextMove = m_TimeLastMove + m_MoveDelay;
		m_HaveMove = false;
	}
}
