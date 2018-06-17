#pragma once
#include "stdafx.h"
#include "Cell.h"
#include "RandomGenerator.h"
#include "Territory.h"

using namespace std;
using namespace CellInfo;

class CState
{
public:
	CState(const Territory & territory, const long & shellsCost) : m_territory(territory), SHELL_COST(shellsCost)
	{}

	bool Shoot(CState & state)
	{
		RandomGenerator generator;
		if (CanShoot(state.GetTerritory()->GetTerritoryCost(), m_shellsCost) && !state.GetTerritory()->IsDestroyed() && !m_territory.IsDestroyed())
		{
			m_shellsCost += SHELL_COST;
			int point_x = generator.GetRandomInt(0, state.GetTerritory()->GetTerritoryWidthSize() - 1);
			int point_y = generator.GetRandomInt(0, state.GetTerritory()->GetTerritoryHeightSize() - 1);
			state.GetTerritory()->DestroyCell(point_x, point_y);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool CanShoot(const long & enemyStateCost, const long & m_shellsCost)
	{
		if (m_shellsCost > enemyStateCost)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	Territory * GetTerritory()
	{
		return &m_territory;
	}

	long GetShellCost()
	{
		return m_shellsCost;
	}

	void PrintTerritory()
	{
		m_territory.PrintTerritory();
	}

	long GetTerritoryCost()
	{
		return m_territory.GetTerritoryCost();
	}

private:
	const long SHELL_COST;
	long m_shellsCost = 0;
	Territory m_territory;
};

