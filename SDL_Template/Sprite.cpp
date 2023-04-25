#include "Sprite.h"

Sprite::Sprite(Vector2* position, Vector2 seize)
	: m_Texture(nullptr)
	, m_Position(position)
	, m_Seize(seize)
{

}

Sprite::~Sprite()
{
	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}
}

bool Sprite::LoadTexture(SDL_Renderer* graphics, const std::string& filename)
{
	m_Texture = IMG_LoadTexture(graphics, filename.c_str());
	if (m_Texture == nullptr)
	{
		SDL_Log("Error loading texture %s", filename.c_str());
		return false;
	}

	return true;
}

void Sprite::Draw(SDL_Renderer* graphics)
{
	Draw(graphics, m_Position, m_Seize);
}

void Sprite::Draw(SDL_Renderer* graphics, Vector2* position, Vector2 seize)
{
	int x = position->GetX();
	int y = position->GetY();
	int w = seize.GetX();
	int h = seize.GetY();
	SDL_Rect dest = SDL_Rect();
	dest.x = x;
	dest.y = y; 
	dest.w = w;
	dest.h = h;

	SDL_RenderCopyEx(graphics, m_Texture, nullptr, &dest, 0.0, nullptr, SDL_FLIP_NONE);
}