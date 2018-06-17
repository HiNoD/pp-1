#pragma once
#include "stdafx.h"
#include <vector>
#include "Cell.h"

using namespace std;
using namespace CellInfo;

class Territory
{
public:
	Territory()
	{}

	Territory(Territory * territory)
	{
		for (size_t i = 0; i < m_territory.size(); i++)
		{
			m_territory.push_back(vector<Cell>());
			for (size_t j = 0; j < m_territory[i].size(); j++)
			{
				m_territory[i].push_back(Cell(territory->GetCell(i, j)));
			}
		}
		SetTerritoryCost(territory->GetTerritoryCost());
	}

	void AddCell(const Cell & cell)
	{
		if (m_territory.size() == 0)
		{
			m_territory[m_territory.size()].push_back(cell);
		}
		else
		{
			m_territory[m_territory.size() - 1].push_back(cell);
		}
	}

	void AddLine()
	{
		m_territory.push_back(vector<Cell>());
	}

	void PrintTerritory()
	{
		for (size_t i = 0; i < m_territory.size(); i++)
		{
			for (size_t j = 0; j < m_territory[i].size(); j++)
			{
				cout << m_territory[i][j].GetCost() << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	bool IsDestroyed()
	{
		for (size_t i = 0; i < m_territory.size(); i++)
		{
			for (size_t j = 0; j < m_territory[i].size(); j++)
			{
				if (m_territory[i][j].GetCost() != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	void SetTerritoryCost()
	{
		for (size_t i = 0; i < m_territory.size(); i++)
		{
			for (size_t j = 0; j < m_territory[i].size(); j++)
			{
				m_territoryCost += m_territory[i][j].GetCost();
			}
		}
	}

	long GetTerritoryCost()
	{
		return m_territoryCost;
	}

	void SetTerritoryCost(const long & cost)
	{
		m_territoryCost = cost;
	}

	long GetTerritoryWidthSize()
	{
		return m_territory.size();
	}

	long GetTerritoryHeightSize()
	{
		return m_territory.at(0).size();
	}

	Cell GetCell(const int & x, const int & y)
	{
		return m_territory.at(x).at(y);
	}

	void DestroyCell(const int & x, const int & y)
	{
		m_territory.at(x).at(y) = DESTROYED;
	}

private:
	vector<vector<Cell>> m_territory;
	long m_territoryCost = 0;
};
