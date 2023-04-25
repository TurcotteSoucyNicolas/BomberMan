#include "Block.h"

Block::Block(Vector2* position, SDL_Renderer* graphics)
{
	m_Position = position;
	m_BlockSprite = new Sprite(m_Position, Vector2(32, 32));
	m_BlockSprite->LoadTexture(graphics, "assets/block.png");
}

Block::~Block()
{
	if (m_BlockSprite != nullptr)
	{
		delete(m_BlockSprite);
		m_BlockSprite = nullptr;
	}
	if (m_Position != nullptr)
	{
		delete(m_Position);
		m_Position = nullptr;
	}
}

void Block::Draw(SDL_Renderer* graphics)
{
	m_BlockSprite->Draw(graphics);
}
