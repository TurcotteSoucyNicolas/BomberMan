#pragma once
#include "Sprite.h"
#include "Vector2.h"
class Gameover
{
public:
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="graphics">permer de load la texture des sprites</param>
	Gameover(SDL_Renderer* graphics);
	/// <summary>
	/// destructeur
	/// </summary>
	~Gameover();
	/// <summary>
	/// permet d'afficher les sprites
	/// </summary>
	/// <param name="graphics"></param>
	void Draw(SDL_Renderer* graphics);
	/// <summary>
	/// permet de faire apparaitre et disparaitre le sprite qui contient le texte
	/// </summary>
	void Update();

private:
	Vector2* m_Position;
	Vector2 m_Seize;
	Sprite* m_MenuBackground;
	Sprite* m_MenuText;
	int m_Timer;
};

