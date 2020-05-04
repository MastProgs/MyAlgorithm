#pragma once
#include <chrono>

class ScopedTimer
{
public:
	ScopedTimer();
	ScopedTimer(bool startMsgOption);
	~ScopedTimer();

#pragma region SingleTimer

public:
	bool SetStart();
	bool SetFinish();
	void PrintTimeCount();

	void Refresh();

private:
	int GetTimeCount();
	void PrintStartCountMsg();

private:
	bool m_startFlag{ false };
	std::chrono::high_resolution_clock::time_point m_start;

	bool m_finishFlag{ false };
	std::chrono::high_resolution_clock::time_point m_finish;

private:
	bool m_startMsgOption{ true };
#pragma endregion SingleTimer
};

