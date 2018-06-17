#pragma once
#include <map>

namespace CellInfo
{
	const enum Type
	{
		EMPTY,
		HOUSE,
		BASE,
		DESTROYED
	};

	const std::map<Type, int> CELL_TYPE = { { EMPTY, 0 },{ HOUSE, 1 },{ BASE, 2 },{ DESTROYED, 3 } };

	const std::map<Type, int> CELL_COST = { { EMPTY, 50 },{ HOUSE, 100 },{ BASE, 300 },{ DESTROYED, 0 } };

	class Cell
	{
	public:
		Cell()
		{}

		Cell(const Cell & cell)
		{
			m_type = cell.m_type;
			m_cost = cell.m_cost;
		}

		Cell(const Type & type)
		{
			m_type = type;
			m_cost = CELL_COST.at(m_type);
		}

		int GetCost()
		{
			return m_cost;
		}

		void SetType(const Type & cellType)
		{
			m_type = cellType;
			m_cost = CELL_COST.at(m_type);
		}

	private:
		Type m_type = EMPTY;
		int m_cost = 0;
	};

}



