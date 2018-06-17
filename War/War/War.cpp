#include "stdafx.h"
#include "Reader.h"
#include "ThreadHandler.h"
#include "Conflict.h"

const int NUM_OF_THREADS = 2;

struct ConflictData
{
	Conflict * m_conflict;	
};

DWORD WINAPI makeShoot(LPVOID * params)
{
	while(true) {
		if (!((ConflictData *)params)->m_conflict->Attack()) {
			break;
		}
	}
	return 0;
}

int main()
{
	Reader reader("input.txt");
	CState state1(reader.ParseState());
	CState state2(reader.ParseState());
	Conflict conflict(state1, state2);
	
	ConflictData conflictData;
	conflictData.m_conflict = &conflict;

	ThreadHandler handler;
	handler.AddThreads((LPTHREAD_START_ROUTINE)makeShoot, (LPVOID)&conflictData, NUM_OF_THREADS);
	handler.RunThreads();
	handler.CloseThreads();

	conflictData.m_conflict->m_firstState.GetTerritory()->PrintTerritory();
	conflictData.m_conflict->m_secondState.GetTerritory()->PrintTerritory();

	return 0;
}