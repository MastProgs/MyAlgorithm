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

private:
	std::vector<int>& m_originData;
};

