#pragma once
#include <windows.h>
#include <vector>

class ThreadHandler
{
public:
	void AddThreads(LPTHREAD_START_ROUTINE threadFunction, LPVOID data, int numOfthreads)
	{
		for (int i = 0; i < numOfthreads; i++)
		{
			m_threads.push_back(CreateThread(NULL, NULL, threadFunction, data, NULL, NULL));
		}
	}

	void CloseThreads()
	{
		for (HANDLE const & threadHandle : m_threads)
		{
			CloseHandle(threadHandle);
		}
	}

	void RunThreads()
	{
		WaitForMultipleObjects(m_threads.size(), m_threads.data(), TRUE, INFINITE);
	}


private:
	std::vector<HANDLE> m_threads;
};

