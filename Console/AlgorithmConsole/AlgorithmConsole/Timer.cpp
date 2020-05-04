#include "Timer.h"

ScopedTimer::ScopedTimer()
{
	SetStart();
}

ScopedTimer::ScopedTimer(bool startMsgOption) : m_startMsgOption{ startMsgOption }
{
	SetStart();
}

ScopedTimer::~ScopedTimer()
{
	SetFinish();
	PrintTimeCount();
}

bool ScopedTimer::SetStart()
{
	if (true == m_startMsgOption)
	{
		PrintStartCountMsg();
	}

	if (false == m_startFlag)
	{
		m_start = std::chrono::high_resolution_clock::now();
		m_startFlag = true;
	}
	return m_startFlag;
}

bool ScopedTimer::SetFinish()
{
	if (false == m_finishFlag)
	{
		m_finish = std::chrono::high_resolution_clock::now();
		m_finishFlag = true;
	}
	return m_finishFlag;
}

int ScopedTimer::GetTimeCount()
{
	if (false == (m_finishFlag && m_startFlag))
	{
		return -1;
	}

	return std::chrono::duration_cast<std::chrono::milliseconds>(m_finish - m_start).count();
}

void ScopedTimer::PrintStartCountMsg()
{
	printf("\n<--- Timer Start! --->\n\n");
}

void ScopedTimer::PrintTimeCount()
{	
	printf("\n<--- %d ms --->\n\n", GetTimeCount());
}

void ScopedTimer::Refresh()
{
	m_startFlag = false;
	m_finishFlag = false;
}
