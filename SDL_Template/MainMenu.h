#pragma once
#include "Sprite.h"
#include "Vector2.h"
class MainMenu
{
public:
	/// <summary>
	/// constructeur du mainMenu
	/// </summary>
	/// <param name="graphics">permet de load la texture des sprite</param>
	MainMenu(SDL_Renderer* graphics);
	/// <summary>
	/// destructeur
	/// </summary>
	~MainMenu();
	/// <summary>
	/// affiche les sprite 
	/// </summary>
	/// <param name="graphics">permet l'affichage</param>
	void Draw(SDL_Renderer* graphics);
	/// <summary>
	/// permet de faire apparaitre et disparaitre la ligne de texte
	/// </summary>
	void Update();

private:
	Vector2* m_Position;
	Vector2 m_Seize;
	Sprite* m_MenuBackground;
	Sprite* m_MenuText;
	int m_Timer;
};

