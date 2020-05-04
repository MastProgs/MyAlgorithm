#pragma once

#include <vector>

class Sorter
{
public:
	Sorter() = delete;
	Sorter(std::vector<int>& i);
	~Sorter() = default;

public:
	void Print();
	void ResetData(std::vector<int>& i);

	void DoSelectionSort();
	void DoBubbleSort();

private:
	std::vector<int>& m_originData;
};

