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
		// �� ���ҵ鿡�� �ּ� ���� ã�´�.
		for (auto iterCurr = iter; iterCurr != m_originData.end(); ++iterCurr)
		{
			if (min > *iterCurr)
			{
				min = *iterCurr;
				tempIter = iterCurr;
			}
		}

		// �ּ� ���̶� ���� ��ġ ���� ��ȯ�Ͽ� �ִ´�
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
	// start, end �� index ���� ����
	if (start >= end)
	{
		// ���Ұ� 1���� ���� ���, ������ �ʿ䰡 ������ return
		return;
	}

	int pivot = start;	// �������� �׳� ù ��° ���ҷ� ����
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)	// start (i) >> ... << (j) end �� ���� �������� �������� �ݺ�
	{
		while (i <= end && m_originData[i] <= m_originData[pivot])	// pivot ������ ū ���� ���� �� ���� �ݺ�
		{
			++i;
		}

		while (j > start && m_originData[j] >= m_originData[pivot])	// pivot ������ ���� ���� ���� �� ���� �ݺ�
		{
			--j;
		}

		if (i > j)	// Ž�� index �� ���� �����ȴٸ�, pivot �� ��ü
		{
			temp = m_originData[j];
			m_originData[j] = m_originData[pivot];
			m_originData[pivot] = temp;
		}
		else
		{
			// �������� �ʾҴٸ� i �� j �� ��ü�Ͽ� ���� ����
			temp = m_originData[j];
			m_originData[j] = m_originData[i];
			m_originData[i] = temp;
		}
	}

	// ���� �и��� ������ ���� ������ �� �������־�� �Ѵ�
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
