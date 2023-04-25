#include "Explosion.h"

Explosion::Explosion(SDL_Renderer* graphics)
	:m_GridIndex(new Vector2(0, 0))
	,m_IsActive(false)
	,m_EndOfExplosion(0)
	,m_Position(new Vector2(0, 0))
{
	m_ExplosionSprite = new Sprite(m_Position, Vector2(32, 32));
	m_ExplosionSprite->LoadTexture(graphics, "assets/Explosion.png");
}

Explosion::~Explosion()
{
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
	if (m_ExplosionSprite = nullptr)
	{
		delete(m_ExplosionSprite);
		m_ExplosionSprite = nullptr;
	}
}

void Explosion::Spawn(Vector2 index, float currentTime)
{
	if (m_GridIndex == nullptr)
	{
		return;
	}
	if (m_Position == nullptr)
	{
		return;
	}
	m_IsActive = true;
	m_EndOfExplosion = currentTime + 1;
	m_GridIndex->SetVector(index.GetX(), index.GetY());
	m_Position->SetVector(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32);
}

void Explosion::Update(float currentTime)
{
	if (m_IsActive && currentTime >= m_EndOfExplosion)
	{
		m_IsActive = false;
	}
}

void Explosion::Draw(SDL_Renderer* graphics)
{
	if (m_ExplosionSprite == nullptr)
	{
		return;
	}
	if (m_IsActive)
	{
		m_ExplosionSprite->Draw(graphics);
	}
}
