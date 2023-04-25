#pragma once
#include "SDL_image.h"
#include "Vector2.h"
#include <string>

class Sprite
{
public:
	Sprite(Vector2* position, Vector2 seize);
	~Sprite();

	bool LoadTexture(SDL_Renderer* graphics, const std::string& filename);

	void Draw(SDL_Renderer* graphics);
private:
	void Draw(SDL_Renderer* graphics, Vector2* position, Vector2 seize);

	SDL_Texture* m_Texture;
	Vector2* m_Position;
	Vector2 m_Seize;
};

