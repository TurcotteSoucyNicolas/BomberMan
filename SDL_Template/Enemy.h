#pragma once
#include "Sprite.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
class Enemy
{
public:
	/// <summary>
	/// enum pour indiquer quelle direction l'ennemy doit regarder
	/// </summary>
	enum Facing { UP, DOWN, LEFT, RIGHT };
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="graphics">permet de load la texture du sprite</param>
	/// <param name="gridIndex">position en vecteur2 de l'enemy dans la grid</param>
	Enemy(SDL_Renderer* graphics, Vector2* gridIndex);
	/// <summary>
	/// destructeur
	/// </summary>
	~Enemy();
	/// <summary>
	/// indique si le delay entre les deplacement est terminer
	/// </summary>
	/// <param name="currentTime">temps present</param>
	/// <returns>true si l'ennemy doit bouger</returns>
	bool HaveToMove(float currentTime);
	/// <summary>
	/// met a jour sa position dans l'ecran en fonction de sa position dans la grille
	/// </summary>
	void SetPosition() { m_Position->SetVector(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32); }
	/// <summary>
	/// affiche le sprite de l'enemy
	/// </summary>
	/// <param name="graphics">permet l'affichage</param>
	void Draw(SDL_Renderer* graphics);
	/// <summary>
	/// indique quel sprite de l'enemy doit etre afficher en fonction du son déplacement
	/// </summary>
	/// <param name="Show">quelle direction l'enemy doit regarder</param>
	void SetSideToShow(Facing Show) { m_SpriteToShow = Show; }
	/// <summary>
	/// 
	/// </summary>
	/// <param name="currentTime"></param>
	void Update(float currentTime);
	/// <summary>
	/// regarde si l'enemy est en vie et si il a bouger lui attribue un nouveau delay de mouvement
	/// </summary>
	void SetHaveMove() { m_HaveMove = true; }
	/// <summary>
	/// disable l'enemy
	/// </summary>
	void Kill() { m_IsAlive = false; }
	/// <summary>
	/// retourne si l'enemy est actif
	/// </summary>
	/// <returns>true si actif</returns>
	bool GetIfAlive() { return m_IsAlive; }
	/// <summary>
	/// retourne la position de l'enemy dans la grid
	/// </summary>
	/// <returns>Vecteur2 ligne, colone</returns>
	Vector2* GetGridIndex() { return m_GridIndex; }
private:
	Sprite* m_EnemySpriteDown;
	Sprite* m_EnemySpriteUp;
	Sprite* m_EnemySpriteLeft;
	Sprite* m_EnemySpriteRight;
	Vector2* m_Position;
	Vector2* m_GridIndex;
	int m_SpriteToShow;
	int m_MoveDelay;
	float m_TimeLastMove;
	float m_TimeNextMove;
	bool m_HaveMove;
	bool m_IsAlive;
};

