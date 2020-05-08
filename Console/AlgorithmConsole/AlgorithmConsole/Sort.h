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
	void DoInsertionSort();
	void DoQuickSort();
	void DoReversQuickSort();

private:
	void QuickSort(int start, int end);
	void ReverseQuickSort(int start, int end);

private:
	std::vector<int>& m_originData;
};

