#include "Grid.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
Grid::Grid(SDL_Renderer* graphics)
	:m_PlayerIsAlive(true)
	,m_Victory(false)
	,m_BombPosition(Vector2(1, 1))
	, m_KillCount(0)
{
	if (!m_HitTile.empty())
	{
		m_HitTile.clear();
	}
	
	for (int row = 0; row < 13; row++)
	{
		srand((unsigned)time(NULL));
		m_Grid.push_back(std::vector<char>());
		m_MovePossible.push_back(Vector2(-1, 0));
		m_MovePossible.push_back(Vector2(1, 0));
		m_MovePossible.push_back(Vector2(0, -1));
		m_MovePossible.push_back(Vector2(0, 1));
		for (int column = 0; column < 15; column++)
		{
			if (column == 0 || column == 14 || row == 0 || row == 12 || row % 2 == 0 && column % 2 == 0)
			{
				m_Grid[row].push_back(BLOCK);
				Block* block = new Block(new Vector2(column * 32, row * 32), graphics);
				m_BlockList.push_back(block);
			}
			else if (row == 1 && column == 1)
			{
				m_Grid[row].push_back(PLAYER);
			}
			else
			{
				m_Grid[row].push_back(EMPTY);
				if (row == 1 && column == 2 || row == 2 && column == 1)
				{
					continue;
				}
				m_EmptyTile.push_back(Vector2(row, column));
			}
		}
	}
	int emptyspace = m_EmptyTile.size() + 2;
	while (m_DestructibleList.size() <= 0.30 * emptyspace)
	{
		int index = rand() % m_EmptyTile.size();
		m_Grid[m_EmptyTile[index].GetX()][m_EmptyTile[index].GetY()] = DESTRUCTIBLE;
		Destructible* block = new Destructible(graphics, new Vector2(m_EmptyTile[index].GetX(), m_EmptyTile[index].GetY()));
		if (m_DestructibleList.empty())
		{
			if (block != nullptr)
			{
				block->HaveTheEnd();
			}
		}
		m_DestructibleList.push_back(block);
		m_EmptyTile.erase(m_EmptyTile.begin() + index);
	}
	for (int i = 0; i < 5; i++)
	{
		Explosion* explosion = new Explosion(graphics);
		m_ExplosionList.push_back(explosion);
	}
}

Grid::~Grid()
{
	for (auto var : m_BlockList)
	{
		if (var != nullptr)
		{
			delete(var);
			var = nullptr;
		}
	}
	for (auto var : m_ExplosionList)
	{
		if (var != nullptr)
		{
			delete(var);
			var = nullptr;
		}
	}
	for (auto var : m_DestructibleList)
	{
		if (var != nullptr)
		{
			delete(var);
			var = nullptr;
		}
	}
}

void Grid::Update(float currentTime)
{
	for (auto var : m_ExplosionList)
	{
		if (var != nullptr)
		{
			var->Update(currentTime);
			if (!var->GetIsActive() && m_Grid[var->GetIndex().GetX()][var->GetIndex().GetY()] == EXPLOSION)
			{
				m_Grid[var->GetIndex().GetX()][var->GetIndex().GetY()] = EMPTY;
			}
		}
	} 
}

bool Grid::Move(Vector2* initialposition, Vector2 movement, GridElement Whatmoving)
{
	if (initialposition != nullptr)
	{

		Vector2 newPosition(initialposition->GetX() + movement.GetX(), initialposition->GetY() + movement.GetY());
		if (m_Grid[newPosition.GetX()][newPosition.GetY()] == EMPTY)
		{
			if (m_Grid[initialposition->GetX()][initialposition->GetY()] == BOMBANDPLAYER)
			{
				m_Grid[initialposition->GetX()][initialposition->GetY()] = BOMB;
			}
			else
			{
				m_Grid[initialposition->GetX()][initialposition->GetY()] = EMPTY;
			}
			m_Grid[newPosition.GetX()][newPosition.GetY()] = Whatmoving;
			initialposition->SetVector(newPosition.GetX(), newPosition.GetY());
			return true;
		}
		else if (m_Grid[newPosition.GetX()][newPosition.GetY()] == EXIT && Whatmoving == PLAYER)
		{
			m_Victory = true;
			return true;
		}
		else if (m_Grid[newPosition.GetX()][newPosition.GetY()] == PLAYER && Whatmoving == ENEMY ||
			m_Grid[newPosition.GetX()][newPosition.GetY()] == ENEMY && Whatmoving == PLAYER)
		{
			m_Grid[initialposition->GetX()][initialposition->GetY()] = EMPTY;
			m_Grid[newPosition.GetX()][newPosition.GetY()] = Whatmoving;
			initialposition->SetVector(newPosition.GetX(), newPosition.GetY());
			m_PlayerIsAlive = false;
			return true;
		}
		else if (m_Grid[newPosition.GetX()][newPosition.GetY()] == EXPLOSION)
		{
			if (Whatmoving == PLAYER)
			{
				m_PlayerIsAlive = false;
				return true;
			}
			else if (Whatmoving == ENEMY)
			{
				m_Grid[initialposition->GetX()][initialposition->GetY()] = EMPTY;
				initialposition->SetVector(newPosition.GetX(), newPosition.GetY());
				KillCount();
				m_HitTile.push_back(newPosition);
				return true;
			}
		}
	}
	return false;

}

Vector2 Grid::GiveEmptyTileIndex(GridElement GiveTo)
{
	int index = rand() % m_EmptyTile.size();
	Vector2 value = Vector2(m_EmptyTile[index].GetX(), m_EmptyTile[index].GetY());
	m_Grid[value.GetX()][value.GetY()] = GiveTo;
	m_EmptyTile.erase(m_EmptyTile.begin() + index);
	return Vector2(value.GetX(), value.GetY());
}

void Grid::SetBomb(const Vector2* index)
{
	if (index != nullptr)
	{
		m_BombPosition = *index;
		m_Grid[Vector2(*index).GetX()][Vector2(*index).GetY()] = BOMBANDPLAYER;
	}
}

void Grid::PlaceExplosion(float currentTime)
{
	if (m_Grid[m_BombPosition.GetX()][m_BombPosition.GetY()] == BOMBANDPLAYER)
	{
		m_PlayerIsAlive = false;
	}
	SetExplosion();
	for (auto indexVar : m_ExplosionIndexList)
	{
		if (m_Grid[indexVar.GetX()][indexVar.GetY()] == ENEMY)
		{
			KillCount();
			m_HitTile.push_back(indexVar);
			m_Grid[indexVar.GetX()][indexVar.GetY()] = EXPLOSION;
			for (auto explosionVar : m_ExplosionList)
			{
				if (explosionVar != nullptr)
				{
					if (!explosionVar->GetIsActive())
					{
						explosionVar->Spawn(indexVar, currentTime);
						break;
					}
				}
			}
		}
		else if (m_Grid[indexVar.GetX()][indexVar.GetY()] == EMPTY || m_Grid[indexVar.GetX()][indexVar.GetY()] == BOMB)
		{
			m_Grid[indexVar.GetX()][indexVar.GetY()] = EXPLOSION;
			for (auto explosionVar : m_ExplosionList)
			{
				if (explosionVar != nullptr)
				{
					if (!explosionVar->GetIsActive())
					{
						explosionVar->Spawn(indexVar, currentTime);
						break;
					}
				}
			}
		}
		else if (m_Grid[indexVar.GetX()][indexVar.GetY()] == DESTRUCTIBLE)
		{
			for (auto destruVar : m_DestructibleList)
			{
				if (destruVar != nullptr)
				{
					if (destruVar->GetIndex().GetX() == indexVar.GetX() && destruVar->GetIndex().GetY() == indexVar.GetY())
					{
						if (destruVar->GetHaveEnd())
						{
    						m_Grid[indexVar.GetX()][indexVar.GetY()] = EXIT;
							destruVar->Destroy();
							break;
						}
						else
						{
							m_Grid[indexVar.GetX()][indexVar.GetY()] = EXPLOSION;
							destruVar->Destroy();
							break;
						}
					}
				}
			} 
			for (auto explosionVar : m_ExplosionList)
			{
				if (explosionVar != nullptr)
				{
					if (!explosionVar->GetIsActive())
					{
						explosionVar->Spawn(indexVar, currentTime);
						break;
					}
				}
			}
		}
	}
}

void Grid::Draw(SDL_Renderer* graphics)
{
	for (auto var : m_BlockList)
	{
		if (var != nullptr)
		{
			var->Draw(graphics);
		}
	}
	for (auto var : m_DestructibleList)
	{
		if (var != nullptr)
		{
			var->Draw(graphics);
		}
	}
	for (auto var : m_ExplosionList)
	{
		if (var != nullptr)
		{
			var->Draw(graphics);
		}
	}
}

void Grid::KillCount()
{
	m_KillCount++;
	if (m_KillCount >= 6)
	{
		for (auto var : m_DestructibleList)
		{
			if (var != nullptr)
			{
				if (var->GetHaveEnd())
				{
					m_Grid[var->GetIndex().GetX()][var->GetIndex().GetY()] = EXIT;
				}
				else
				{
					m_Grid[var->GetIndex().GetX()][var->GetIndex().GetY()] = EMPTY;
				}
				var->Destroy();
			}
		}
	}
}

void Grid::SetExplosion()
{
	if (!m_ExplosionIndexList.empty())
	{
		m_ExplosionIndexList.clear();
	}
	std::vector<Vector2> templist;
	templist.push_back(Vector2(m_BombPosition.GetX(), m_BombPosition.GetY()));
	templist.push_back(Vector2(m_BombPosition.GetX() + 1, m_BombPosition.GetY()));
	templist.push_back(Vector2(m_BombPosition.GetX() - 1, m_BombPosition.GetY()));
	templist.push_back(Vector2(m_BombPosition.GetX(), m_BombPosition.GetY() + 1));
	templist.push_back(Vector2(m_BombPosition.GetX(), m_BombPosition.GetY() - 1));
	for (auto var : templist)
	{
		if (m_Grid[var.GetX()][var.GetY()] == PLAYER)
		{
			m_PlayerIsAlive = false;
			return;
		}
		if (m_Grid[var.GetX()][var.GetY()] != BLOCK)
		{
			m_ExplosionIndexList.push_back(var);
		}
	}
}
