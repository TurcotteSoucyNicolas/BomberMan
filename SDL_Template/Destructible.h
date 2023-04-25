#pragma once
#include "Sprite.h";
class Destructible
{
public:
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="graphics">permet de load la texture du sprite</param>
	/// <param name="gridIndex">position du destructible dans la grid en vecteur2 (ligne, colone)</param>
	Destructible(SDL_Renderer* graphics, Vector2* gridIndex);
	/// <summary>
	/// destructeur
	/// </summary>
	~Destructible();
	/// <summary>
	/// retourne la position du destructible dans la grid
	/// </summary>
	/// <returns>Vecteur2(ligne, colone)</returns>
	Vector2 GetIndex() { return *m_GridIndex; }
	/// <summary>
	/// disable le destructible
	/// </summary>
	void Destroy() { m_Destroyed = true; }
	/// <summary>
	/// retourne is le destructible possede la porte de fin
	/// </summary>
	/// <returns>true si il possede la fin</returns>
	bool GetHaveEnd() { return m_HaveEnd; }
	/// <summary>
	/// set is le destructible possede la porte de fin
	/// </summary>
	void HaveTheEnd() { m_HaveEnd = true; };
	/// <summary>
	/// affiche les sprites du destructible
	/// </summary>
	/// <param name="graphics">permet l'affichade du sprite</param>
	void Draw(SDL_Renderer* graphics);
private:
	bool m_HaveEnd;
	Vector2* m_Position;
	Vector2* m_GridIndex;
	Sprite* m_DestructibleSprite;
	Sprite* m_DoorSprite;
	bool m_Destroyed;
};
