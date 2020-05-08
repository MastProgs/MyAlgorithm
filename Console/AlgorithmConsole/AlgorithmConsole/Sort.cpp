#include "Sort.h"

#include <iostream>
#include <iterator>

Sorter::Sorter(std::vector<int>& i)
	: m_originData{ i }
{
}

void Sorter::Print()
{
	std::copy(m_originData.begin(), m_originData.end(), std::ostream_iterator<int>(std::cout, " "));
}

void Sorter::ResetData(std::vector<int>& i)
{
	m_originData = i;
}

void Sorter::DoSelectionSort()
{
	int min = INT_MAX;
	auto tempIter = m_originData.begin();

	for (auto iter = m_originData.begin(); iter != m_originData.end(); ++iter)
	{
		// 뒷 원소들에서 최소 값을 찾는다.
		for (auto iterCurr = iter; iterCurr != m_originData.end(); ++iterCurr)
		{
			if (min > *iterCurr)
			{
				min = *iterCurr;
				tempIter = iterCurr;
			}
		}

		// 최소 값이랑 현재 위치 값을 교환하여 넣는다
		*tempIter = *iter;
		*iter = min;
		min = INT_MAX;
	}
}

void Sorter::DoBubbleSort()
{
	int temp;
	for (int i = 0; i < m_originData.size(); ++i)
	{
		for (int j = 0; j < (m_originData.size() - 1 - i); ++j)
		{
			if (m_originData[j] > m_originData[j + 1])
			{
				temp = m_originData[j];
				m_originData[j] = m_originData[j + 1];
				m_originData[j + 1] = temp;
			}
		}
	}
}

void Sorter::DoInsertionSort()
{
	int temp;
	for (auto iter = m_originData.begin(); iter != m_originData.end(); ++iter)
	{
		auto tempIter = m_originData.rbegin();
		for (auto rIter = std::make_reverse_iterator(iter); rIter != m_originData.rend(); ++rIter)
		{
			if (*(rIter - 1) < *rIter)
			{
				temp = *rIter;
				*rIter = *(rIter - 1);
				*(rIter - 1) = temp;
			}
			else
			{
				break;
			}
		}
	}
}

void Sorter::DoQuickSort()
{
	QuickSort(0, m_originData.size() - 1);
}

void Sorter::DoReversQuickSort()
{
	ReverseQuickSort(0, m_originData.size() - 1);
}

void Sorter::QuickSort(int start, int end)
{
	// start, end 는 index 구간 범위
	if (start >= end)
	{
		// 원소가 1개만 남은 경우, 정렬할 필요가 없으니 return
		return;
	}

	int pivot = start;	// 기준점을 그냥 첫 번째 원소로 잡음
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)	// start (i) >> ... << (j) end 가 서로 엇갈리기 전까지만 반복
	{
		while (i <= end && m_originData[i] <= m_originData[pivot])	// pivot 값보다 큰 값을 만날 때 까지 반복
		{
			++i;
		}

		while (j > start && m_originData[j] >= m_originData[pivot])	// pivot 값보다 작은 값을 만날 때 까지 반복
		{
			--j;
		}

		if (i > j)	// 탐색 index 가 서로 엇갈렸다면, pivot 과 교체
		{
			temp = m_originData[j];
			m_originData[j] = m_originData[pivot];
			m_originData[pivot] = temp;
		}
		else
		{
			// 엇갈리지 않았다면 i 와 j 를 교체하여 정렬 진행
			temp = m_originData[j];
			m_originData[j] = m_originData[i];
			m_originData[i] = temp;
		}
	}

	// 남은 분리된 구간에 대한 정렬을 또 진행해주어야 한다
	QuickSort(start, j - 1);
	QuickSort(j + 1, end);
}

void Sorter::ReverseQuickSort(int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)
	{
		while (i <= end && m_originData[i] >= m_originData[pivot])
		{
			++i;
		}

		while (j > start && m_originData[j] <= m_originData[pivot])
		{
			--j;
		}

		if (i > j)
		{
			temp = m_originData[j];
			m_originData[j] = m_originData[pivot];
			m_originData[pivot] = temp;
		}
		else
		{
			temp = m_originData[j];
			m_originData[j] = m_originData[i];
			m_originData[i] = temp;
		}
	}

	ReverseQuickSort(start, j - 1);
	ReverseQuickSort(j + 1, end);
}
