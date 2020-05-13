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

void Sorter::DoMergeSort()
{
	// �ӽ� �Ű� ����� ����
	std::vector<int> tempArr;
	tempArr.reserve(m_originData.size());
	for (auto d : m_originData)
	{
		tempArr.emplace_back(0);
	}

	MergeSort(0, m_originData.size() - 1, tempArr);
}

void Sorter::DoHeapSort()
{
	auto makeHeap = [](int maxIndex, std::vector<int>& v) 
	{
		// ���� �ִ� �� ������ �ǰԲ� �迭�� ����
		for (int i = 1; i < maxIndex; i++)
		{
			int currIdx = i;
			do
			{
				int parentIdx = (currIdx - 1) / 2;
				if (v[parentIdx] < v[currIdx])
				{
					int temp = v[parentIdx];
					v[parentIdx] = v[currIdx];
					v[currIdx] = temp;
				}
				currIdx = parentIdx;
			} while (currIdx != 0);
		}
	};

	makeHeap(m_originData.size(), m_originData);

	// �� �ֻ�� ���� �ĸ����� �̵��Ͽ�, index ���� �ٿ��ָ鼭 ���� ������ ����
	for (int i = m_originData.size() - 1; i >= 0; --i)
	{
		// �� �ֻ�� ����, ������ �� ���� ��ü
		int temp = m_originData[0];
		m_originData[0] = m_originData[i];
		m_originData[i] = temp;

		//makeHeap(i, m_originData);

		// ������ ���� �ٽ� �� ������ �س�����
		int parent = 0;
		int curr = 1;
		do
		{
			curr = 2 * parent + 1;
			// �ڽ� �߿� �� ū ���� ã��
			if (curr < i - 1 && m_originData[curr] < m_originData[curr + 1])
			{
				++curr;
			}

			// �θ𺸴� �ڽ��� ũ�ٸ� ��ȯ
			if (curr < i && m_originData[parent] < m_originData[curr])
			{
				temp = m_originData[parent];
				m_originData[parent] = m_originData[curr];
				m_originData[curr] = temp;
			}
			parent = curr;
		} while (curr < i);
	}
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

void Sorter::MergeSort_Impl(int start, int middle, int end, std::vector<int>& tempArr)
{
	int i = start;		// ���� ���� �� ���� index
	int j = middle + 1;	// ���� ���� �� ���� index
	int k = start;	// ������ �� �迭�� ���� �� ���� index

	while (i <= middle && j <= end)
	{
		// i ĭ�� j ĭ ���ؼ� ���� �༮�� �����ϴ� �迭�� ������
		if (m_originData[i] <= m_originData[j])
		{
			tempArr[k] = m_originData[i];
			++i;
		}
		else
		{
			tempArr[k] = m_originData[j];
			++j;
		}
		++k;
	}

	// i �� j ���� ������ ����ٸ�, ���� �������� �׳� ������� �����ؼ� ������ ��
	if (i > middle)
	{
		for (int t = j; t <= end; ++t)
		{
			tempArr[k] = m_originData[t];
			++k;
		}
	}
	else
	{
		for (int t = i; t <= middle; ++t)
		{
			tempArr[k] = m_originData[t];
			++k;
		}
	}

	// ������ �����͸� ���� �迭�� ����
	for (int t = start; t <= end; ++t)
	{
		m_originData[t] = tempArr[t];
	}
}

void Sorter::MergeSort(int start, int end, std::vector<int>& tempArr)
{
	if (start < end)	// �̰� �̿��� ����� ���� �� ���� 1���� �����
	{
		int middle = (start + end) / 2;
		MergeSort(start, middle, tempArr);
		MergeSort(middle + 1, end, tempArr);
		MergeSort_Impl(start, middle, end, tempArr);
	}
}
