#pragma once
#include "Vector2.h"
#include "Sprite.h"
class Player
{
public:
	/// <summary>
	/// direction du sprite du player
	/// </summary>
	enum PlayerFacing { UP, DOWN, LEFT, RIGHT };
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="graphics">permet de load la texture du sprite</param>
	Player(SDL_Renderer* graphics);
	/// <summary>
	/// destructeur
	/// </summary>
	~Player();
	/// <summary>
	/// place le sprite du joueur selon la grille de jeu
	/// </summary>
	void SetPosition() { m_Position->SetVector(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32); }
	/// <summary>
	/// affiche le sprite du joueur
	/// </summary>
	/// <param name="graphics">permet d'afficher le sprite</param>
	void Draw(SDL_Renderer* graphics);
	/// <summary>
	/// permet de choisir le sprite du joueur a afficher
	/// </summary>
	/// <param name="Show">la direction dans laquelle le personnage doit regarder</param>
	void SetSideToShow(PlayerFacing Show) { m_SpriteToShow = Show; };
	/// <summary>
	/// retourne l'index correspondant dans la grille correspondant a la position du personnage 
	/// </summary>
	/// <returns>pointeur de Vecteur2</returns>
	Vector2* GetGridIndex() { return m_GridIndex; };
private:
	Sprite* m_PlayerSpriteDown;
	Sprite* m_PlayerSpriteUp;
	Sprite* m_PlayerSpriteLeft;
	Sprite* m_PlayerSpriteRight;
	Vector2* m_Position;
	Vector2* m_GridIndex;
	int m_SpriteToShow;
};

