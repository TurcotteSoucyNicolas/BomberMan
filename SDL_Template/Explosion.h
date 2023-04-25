#pragma once
#include"Sprite.h"
class Explosion
{
public:
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="graphics">sert a load les textures des sprites</param>
	Explosion(SDL_Renderer* graphics);
	/// <summary>
	/// destructeur
	/// </summary>
	~Explosion();
	/// <summary>
	/// active une explosion
	/// </summary>
	/// <param name="index">Index correspondant a la position de l'explosion dans la grid</param>
	/// <param name="currentTime">temps present servant a set une valeur pour désactiver l'explosion</param>
	void Spawn(Vector2 index, float currentTime);
	/// <summary>
	/// retoure l'index correspondant a la position de l'explosion dans la grid
	/// </summary>
	/// <returns>Vecteur2 ligne, colone</returns>
	Vector2 GetIndex() { return *m_GridIndex; }
	/// <summary>
	/// désactive l'explosion quand le temps courant est plus élever que le temps de fin d'explosion
	/// </summary>
	/// <param name="currentTime">temps courant</param>
	void Update(float currentTime);
	/// <summary>
	/// affiche l'explosion
	/// </summary>
	/// <param name="graphics">obligatoire pour afficher un sprite</param>
	void Draw(SDL_Renderer* graphics);
	/// <summary>
	/// indique si l'explosion est active
	/// </summary>
	/// <returns>true si active</returns>
	bool GetIsActive() { return m_IsActive; }
private:
	Sprite* m_ExplosionSprite;
	Vector2* m_GridIndex;
	Vector2* m_Position;
	bool m_IsActive;
	float m_EndOfExplosion;
};

