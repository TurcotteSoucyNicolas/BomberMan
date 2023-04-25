#include "Player.h"

Player::Player(SDL_Renderer* graphics)

{
	m_SpriteToShow = DOWN;
	m_GridIndex = new Vector2(1, 1);
	m_Position = new Vector2(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32); 
	m_PlayerSpriteDown = new Sprite(m_Position, Vector2(32, 32));
	m_PlayerSpriteUp = new Sprite(m_Position, Vector2(32, 32));
	m_PlayerSpriteLeft = new Sprite(m_Position, Vector2(32, 32));
	m_PlayerSpriteRight = new Sprite(m_Position, Vector2(32, 32));
	m_PlayerSpriteDown->LoadTexture(graphics, "assets/linkFront1.png");
	m_PlayerSpriteUp->LoadTexture(graphics, "assets/linkUp.png");
	m_PlayerSpriteLeft->LoadTexture(graphics, "assets/linkLeft.png");
	m_PlayerSpriteRight->LoadTexture(graphics, "assets/linkRight.png");
}


Player::~Player()
{
	if (m_PlayerSpriteDown != nullptr)
	{
		delete(m_PlayerSpriteDown);
		m_PlayerSpriteDown = nullptr;
	}
	if (m_PlayerSpriteUp != nullptr)
	{
		delete(m_PlayerSpriteUp);
		m_PlayerSpriteUp = nullptr;
	}
	if (m_PlayerSpriteLeft != nullptr)
	{
		delete(m_PlayerSpriteLeft);
		m_PlayerSpriteLeft = nullptr;
	}
	if (m_PlayerSpriteRight != nullptr)
	{
		delete(m_PlayerSpriteRight);
		m_PlayerSpriteRight = nullptr;
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

void Player::Draw(SDL_Renderer* graphics)
{
	if (m_PlayerSpriteUp == nullptr)
	{
		return;
	}
	if (m_PlayerSpriteDown == nullptr)
	{
		return;
	}
	if (m_PlayerSpriteLeft == nullptr)
	{
		return;
	}
	if (m_PlayerSpriteRight == nullptr)
	{
		return;
	}
	if (m_SpriteToShow == UP)
	{
		m_PlayerSpriteUp->Draw(graphics);
	}
	else if (m_SpriteToShow == DOWN)
	{
		m_PlayerSpriteDown->Draw(graphics);
	}
	else if (m_SpriteToShow == LEFT)
	{
		m_PlayerSpriteLeft->Draw(graphics);
	}
	else if (m_SpriteToShow == RIGHT)
	{
		m_PlayerSpriteRight->Draw(graphics);
	}
}
