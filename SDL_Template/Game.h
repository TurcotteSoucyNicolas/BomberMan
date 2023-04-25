#pragma once
#include "SDL.h"
#include "Input.h"
#include "MainMenu.h"
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Gameover.h"
#include "Bomb.h"
#include "VictoryScreen.h"
class Game
{

public:
	/// <summary>
	/// destructeur
	/// </summary>
	~Game();
	/// <summary>
	/// inicialise les variables 
	/// </summary>
	/// <param name="graphics"></param>
	void Init(SDL_Renderer* graphics);
	/// <summary>
	/// contient la logique d'une partie code jouer a chaque frame
	/// </summary>
	void Update();
	/// <summary>
	/// affiche les éléments de la partie
	/// </summary>
	/// <param name="graphics">permet d'afficher les elements</param>
	void Draw(SDL_Renderer* graphics);
	/// <summary>
	/// permet de mettre fin a la partie
	/// </summary>
	/// <returns>false met fin a la partie</returns>
	bool GameRunning() { return m_GameRunning; };
private:
	/// <summary>
	/// enum des états de jeu (MENU = écran titre, GAME = la partie de jeu, GAMEOVER = partie perdu(le player est mort), VICTORY = partie gagner (le player trouver et atteint la sortie
	/// </summary>
	enum GameState { MENU, GAME, GAMEOVER, VICTORY};
	Input* m_InputManager;
	MainMenu* m_MainMenu;
	Grid* m_Grid;
	Gameover* m_GameOver;
	Player* m_Player;
	Bomb* m_Bomb;
	VictoryScreen* m_VictoryScreen;
	std::list<Enemy*> m_EnemyList;
	int m_GameState;
	float m_Timer;
	float m_TimeAtBeginning;
	float m_currentTime;
	bool m_GameRunning = true;
};