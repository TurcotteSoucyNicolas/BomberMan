#pragma once
#include "SDL.h"
#include "Sprite.h";
#include "Vector2.h"
#include <list>
class Block
{
public:
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="position">position ou afficher le sprite</param>
	/// <param name="graphics">permet de load la texture du sprite</param>
	Block(Vector2* position, SDL_Renderer* graphics);
	/// <summary>
	/// destructeur
	/// </summary>
	~Block();
	/// <summary>
	/// affiche le sprite
	/// </summary>
	/// <param name="graphics">permet d'afficher le sprite</param>
	void Draw(SDL_Renderer* graphics);

private:
	Sprite* m_BlockSprite;
	Vector2* m_Position;
};

