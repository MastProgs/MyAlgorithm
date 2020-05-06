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
