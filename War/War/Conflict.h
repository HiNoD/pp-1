#pragma once
#include "State.h"
#include "ThreadHandler.h"

class Conflict
{
public:
	Conflict(CState& st1, CState& st2) : m_firstState(st1), m_secondState(st2)
	{
		m_firstState.PrintTerritory();
		cout << m_firstState.GetTerritoryCost() << endl;
		m_secondState.PrintTerritory();
		cout << m_secondState.GetTerritoryCost() << endl;
	}

	bool Attack()
	{
		WaitForSingleObject(m_mutex, INFINITE);

		bool res = true;

		if (!m_firstState.Shoot(m_secondState) || !m_secondState.Shoot(m_firstState)) {
			res = false;
		}
		else 
		{
			m_firstState.PrintTerritory();
			m_secondState.PrintTerritory();
		}

		ReleaseMutex(m_mutex);

		return res;
	}

	~Conflict()
	{
		CloseHandle(m_mutex);
	}

	CState m_firstState;
	CState m_secondState;

private:
	CONST HANDLE m_mutex = CreateMutex(NULL, FALSE, NULL);
};

