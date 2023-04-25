#pragma once
#include "Sprite.h"
class Bomb
{
public:
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="graphics">permet de load la texture</param>
	Bomb(SDL_Renderer* graphics);
	/// <summary>
	/// destructeur
	/// </summary>
	~Bomb();
	/// <summary>
	/// met a jour les information de si la bombe est active ou is elle a exploser
	/// </summary>
	/// <param name="currentTime">temp courant</param>
	void Update(float currentTime);
	/// <summary>
	/// active une bombe a la position du joueur et inicialise son minuteur 
	/// </summary>
	/// <param name="currentTime">temp present</param>
	/// <param name="Index">position du joueur dans la grid en Vecteur2(ligne, colone)</param>
	void SpawnBomb(float currentTime, Vector2 Index);
	/// <summary>
	/// met a jour sa position a l'ecran en fonction de sa position dans la grid
	/// </summary>
	void SetPosition() { m_Position->SetVector(m_GridIndex->GetY() * 32, m_GridIndex->GetX() * 32); }
	/// <summary>
	/// retourne si la bombe est active
	/// </summary>
	/// <returns>true si active</returns>
	bool GetIsActive() { return m_IsActive; }
	/// <summary>
	/// affiche a l'ecran la bombe
	/// </summary>
	/// <param name="graphics">permet d'afficher le sprite</param>
	void Draw(SDL_Renderer* graphics);
	/// <summary>
	/// retourne si la bombe a exploser
	/// </summary>
	/// <returns>true si elle a exploser</returns>
	bool GetIfDone() { return m_Done; }
	/// <summary>
	/// retourne la position de la bombe dans la grid
	/// </summary>
	/// <returns>Vector2(ligne, colone)</returns>
	const Vector2* GetGridIndex() { return m_GridIndex; }
	/// <summary>
	/// set la valeur de si la bombe a exploser a false 
	/// </summary>
	void SetDone() { m_Done = false; }
private:
	Sprite* m_BombSprite;
	Vector2* m_GridIndex;
	Vector2* m_Position;
	float m_StartTime;
	float m_EndTime;
	bool m_Done;
	bool m_IsActive;
};

