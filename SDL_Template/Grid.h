#pragma once
#include<vector>
#include<list>
#include"Block.h"
#include"Vector2.h"
#include"Destructible.h"
#include "Explosion.h"
class Grid
{
public:
	/// <summary>
	/// enum des char représentant des éléments du jeux
	/// </summary>
	enum GridElement { PLAYER = 'P', ENEMY = 'E', BLOCK = 'X', DESTRUCTIBLE = 'D', BOMB = 'B', EXIT = 'F', BOMBANDPLAYER = 'M', EMPTY = ' ', EXPLOSION = 'O' };
	/// <summary>
	/// constructeur
	/// </summary>
	/// <param name="graphics">permet de load les textures des sprites</param>
	Grid(SDL_Renderer* graphics);
	/// <summary>
	/// destructeur
	/// </summary>
	~Grid();
	/// <summary>
	/// indique quand les explosions doit etre active et les déactives quand leur délai est dépasser
	/// </summary>
	/// <param name="currentTime">permet de savoir quand les explosions on été active pour une seconde</param>
	void Update(float currentTime);
	/// <summary>
	/// vérifie si les mouvements sont possible et déplace les éléments qui bouge dans la grid
	/// </summary>
	/// <param name="initialposition">index de l'élément qui bouge</param>
	/// <param name="movement">déplacement désirer</param>
	/// <param name="Whatmoving">char qui correspont a l'élément</param>
	/// <returns>true si l'élément a été deplacer</returns>
	bool Move(Vector2* initialposition, Vector2 movement, GridElement Whatmoving);
	/// <summary>
	/// retoure si le player est en vie
	/// </summary>
	/// <returns>true si il est en vie</returns>
	bool PlayerIsAlive() { return m_PlayerIsAlive; };
	/// <summary>
	/// place des elements dans les case vide de la grid
	/// </summary>
	/// <param name="GiveTo">char correspondant a l'élément qui doit etre placer</param>
	/// <returns>l'index de l'élément</returns>
	Vector2 GiveEmptyTileIndex(GridElement GiveTo);
	/// <summary>
	/// retourne une list de Vector2 correspondant au mouvement possible dans la grille (une case vers le haut, une case vers le bas, une case vers la gauche et une case vers la droite
	/// </summary>
	/// <returns>list des mouvement possible</returns>
	std::vector<Vector2> GetMovePossible() { return m_MovePossible; };
	/// <summary>
	/// la liste des index ou un enemy a été toucher par une explosion
	/// </summary>
	/// <returns>list de Vexteur2 correspondant au index de la grid</returns>
	std::vector<Vector2> EnemyHitTile() { return m_HitTile; }
	/// <summary>
	/// vide la liste des index ou les enemy ont été toucher
	/// </summary>
	void EmptyHitTile() { m_HitTile.empty(); }
	/// <summary>
	/// place une bombe a la positon du player dans la grid
	/// </summary>
	/// <param name="index">position du player</param>
	void SetBomb(const Vector2* index);
	/// <summary>
	/// place les explosions dans la grid et vérifie avec quoi elle ont eu une colision
	/// </summary>
	/// <param name="currentTime">temps a laquelle l'explosion commence</param>
	void PlaceExplosion(float currentTime);
	/// <summary>
	/// retoure si le joueur a gagner
	/// </summary>
	/// <returns>true si le joueur a gagner</returns>
	bool GetVictory() { return m_Victory; }
	/// <summary>
	/// affiche tout les éléments de la grid (destructible, bloc, explosion)
	/// </summary>
	/// <param name="graphics">permet d'afficher les sprites</param>
	void Draw(SDL_Renderer* graphics);
private:
	/// <summary>
	/// ajoute et conte le nombre d'enemy mort pour savoir si il faut detruire les destructibles et afficher la fin
	/// </summary>
	void KillCount();
	int m_KillCount;
	/// <summary>
	/// vérifie si le joueur a été toucher par l'explosion de la bombe et ajoute les vecteur2 d'index a la lise m_ExplosionIndexList en enlevant les index correspondants a des blocs indestructible
	/// </summary>
	void SetExplosion();
	std::vector<Vector2> m_ExplosionIndexList;
	std::list<Block*> m_BlockList;
	std::list<Explosion*> m_ExplosionList;
	std::list <Destructible*> m_DestructibleList;
	std::vector<std::vector<char>> m_Grid;
	std::vector<Vector2> m_EmptyTile;
	std::vector<Vector2> m_HitTile;
	std::vector<Vector2> m_MovePossible;
	Vector2 m_BombPosition;
	bool m_PlayerIsAlive;
	bool m_Victory;
};

