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

	void DoMergeSort();

private:
	void QuickSort(int start, int end);
	void ReverseQuickSort(int start, int end);

	void MergeSort_Impl(int start, int middle, int end);
	void MergeSort(int start, int end);

private:
	std::vector<int>& m_originData;
};

