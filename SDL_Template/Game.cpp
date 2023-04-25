#include "Game.h"
Game::~Game()
{
	if (m_InputManager != nullptr)
	{
		delete(m_InputManager);
		m_InputManager = nullptr;
	}
	if (m_MainMenu != nullptr)
	{
		delete(m_MainMenu);
		m_MainMenu = nullptr;
	}
	if (m_Grid != nullptr)
	{
		delete(m_Grid);
		m_Grid = nullptr;
	}
	if (m_GameOver != nullptr)
	{
		delete(m_GameOver);
		m_GameOver = nullptr;
	}
	if (m_Player  != nullptr)
	{
		delete(m_Player);
		m_Player = nullptr;
	}
	if (m_Bomb != nullptr)
	{
		delete(m_Bomb);
		m_Bomb = nullptr;
	}
	for (auto var : m_EnemyList)
	{
		if (var != nullptr)
		{
			delete(var);
			var = nullptr;
		}
	}

}

void Game::Init(SDL_Renderer* graphics)
{
	srand((unsigned)time(NULL));
	m_GameState = MENU;
	m_InputManager = new Input();
	m_MainMenu = new MainMenu(graphics);
	m_GameOver = new Gameover(graphics);
	m_Grid = new Grid(graphics);
	m_Player = new Player(graphics);
	m_Bomb = new Bomb(graphics);
	m_VictoryScreen = new VictoryScreen(graphics);
	m_Timer = 0;
	m_currentTime = 0;
	m_TimeAtBeginning = 0;
	while (m_EnemyList.size() < 6)
	{
		Enemy* enemy = new Enemy(graphics, new Vector2(m_Grid->GiveEmptyTileIndex(m_Grid->ENEMY)));
		m_EnemyList.push_back(enemy);
	}
}

void Game::Update()
{
	m_Timer = SDL_GetTicks() / 1000.0f;
	m_currentTime = m_Timer - m_TimeAtBeginning;
	if (m_InputManager != nullptr)
	{
		m_InputManager->CheckInput();
		if (m_GameState == MENU)
		{
			if (m_MainMenu != nullptr)
			{
				m_MainMenu->Update();
			}
			if (m_InputManager->GetSpace() && !m_InputManager->GetSpaceIsPress())
			{
				m_GameState = GAME;
				m_InputManager->SetMove();
				m_InputManager->SetSpaceIsPress();
				m_TimeAtBeginning = m_Timer;
			}
		}
		else if (m_GameState == GAME)
		{
			if (m_Grid != nullptr)
			{
				m_Grid->Update(m_currentTime);
				if (!m_Grid->EnemyHitTile().empty())
				{
					for (auto index : m_Grid->EnemyHitTile())
					{
						for (auto enemy : m_EnemyList)
						{
							if (enemy != nullptr)
							{
								if (index.GetX() == enemy->GetGridIndex()->GetX() && index.GetY() == enemy->GetGridIndex()->GetY())
								{
									enemy->Kill();
								}
							}
						}
					}
					m_Grid->EmptyHitTile();
				}

				std::vector<Vector2> movelist = m_Grid->GetMovePossible();
				for (auto var : m_EnemyList)
				{
					if (var != nullptr)
					{
						if (!var->GetIfAlive())
						{
							continue;
						}
						var->Update(m_currentTime);
						if (var->HaveToMove(m_currentTime))
						{
							int index = rand() % 4;
							int count = 0;
							while (!m_Grid->Move(var->GetGridIndex(), movelist[index], m_Grid->ENEMY) && count < 15)
							{
								index = rand() % 4;
								movelist = m_Grid->GetMovePossible();
								count++;
							}
							if (index == 0)
							{
								var->SetSideToShow(var->UP);
							}
							else if (index == 1)
							{
								var->SetSideToShow(var->DOWN);
							}
							else if (index == 2)
							{
								var->SetSideToShow(var->LEFT);
							}
							else if (index == 3)
							{
								var->SetSideToShow(var->RIGHT);
							}
							var->SetHaveMove();
							var->SetPosition();
						}
					}
				}
				if (m_Player != nullptr)
				{
					if (m_InputManager->GetDown() && !m_InputManager->GetHaveMove())
					{
						if (m_Grid->Move(m_Player->GetGridIndex(), Vector2(1, 0), m_Grid->PLAYER))
						{
							m_Player->SetSideToShow(m_Player->DOWN);
							m_Player->SetPosition();
							m_InputManager->SetMove();
						}
					}
					else if (m_InputManager->GetUp() && !m_InputManager->GetHaveMove())
					{
						if (m_Grid->Move(m_Player->GetGridIndex(), Vector2(-1, 0), m_Grid->PLAYER))
						{
							m_Player->SetSideToShow(m_Player->UP);
							m_Player->SetPosition();
							m_InputManager->SetMove();
						}
					}
					else if (m_InputManager->GetLeft() && !m_InputManager->GetHaveMove())
					{
						if (m_Grid->Move(m_Player->GetGridIndex(), Vector2(0, -1), m_Grid->PLAYER))
						{
							m_Player->SetSideToShow(m_Player->LEFT);
							m_Player->SetPosition();
							m_InputManager->SetMove();
						}
					}
					else if (m_InputManager->GetRight() && !m_InputManager->GetHaveMove())
					{
						if (m_Grid->Move(m_Player->GetGridIndex(), Vector2(0, 1), m_Grid->PLAYER))
						{
							m_Player->SetSideToShow(m_Player->RIGHT);
							m_Player->SetPosition();
							m_InputManager->SetMove();
						}
					}
					else if (m_InputManager->GetSpace() && !m_InputManager->GetSpaceIsPress())
					{
						if (m_Bomb != nullptr)
						{
							if (!m_Bomb->GetIsActive())
							{
								m_Bomb->SpawnBomb(m_currentTime, *m_Player->GetGridIndex());
								m_Bomb->SetPosition();
								m_Grid->SetBomb(m_Bomb->GetGridIndex());
								m_InputManager->SetSpaceIsPress();
							}
						}
					}
				}
				if (m_Bomb != nullptr)
				{
					m_Bomb->Update(m_currentTime);
					if (m_Bomb->GetIfDone())
					{
						m_Bomb->SetDone();
						m_Grid->PlaceExplosion(m_currentTime);
					}
				}
				if (m_Grid->GetVictory())
				{
					m_GameState = VICTORY;
				}
				if (!m_Grid->PlayerIsAlive())
				{
					m_GameState = GAMEOVER;
				}
			}
		}
		else if (m_GameState == GAMEOVER)
		{
			if (m_GameOver != nullptr)
			{
				m_GameOver->Update();
			}
			if (m_InputManager->GetSpace())
			{
				m_GameRunning = false;
			}
		}
		else if (m_GameState == VICTORY)
		{
			if (m_VictoryScreen != nullptr)
			{
				m_VictoryScreen->Update();
			}
			
			if (m_InputManager->GetSpace())
			{
				m_GameRunning = false;
			}
		}
	}
}

void Game::Draw(SDL_Renderer* graphics)
{
	if (m_GameState == MENU)
	{
		if (m_MainMenu != nullptr)
		{
			m_MainMenu->Draw(graphics);
		}
	}
	else if (m_GameState == GAME)
	{
		if (m_Grid != nullptr)
		{
			m_Grid->Draw(graphics);
		}
		if (m_Bomb != nullptr)
		{
			m_Bomb->Draw(graphics);
		}
		if (m_Player != nullptr)
		{
			m_Player->Draw(graphics);
		}
		for (auto var : m_EnemyList)
		{
			if (var != nullptr)
			{
				var->Draw(graphics);
			}
		}
	}
	else if (m_GameState == GAMEOVER)
	{
		if (m_GameOver != nullptr)
		{
			m_GameOver->Draw(graphics);
		}
	}
	else if (m_GameState == VICTORY)
	{
		if (m_VictoryScreen != nullptr)
		{
			m_VictoryScreen->Draw(graphics);
		}
	}
}