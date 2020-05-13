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

void Sorter::DoMergeSort()
{
	// 임시 옮겨 쓰기용 공간
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
		// 이진 최대 힙 구조가 되게끔 배열을 정리
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

	// 맨 최상단 값을 후면으로 이동하여, index 값을 줄여주면서 힙을 구성해 나감
	for (int i = m_originData.size() - 1; i >= 0; --i)
	{
		// 맨 최상단 값을, 마지막 끝 값과 교체
		int temp = m_originData[0];
		m_originData[0] = m_originData[i];
		m_originData[i] = temp;

		//makeHeap(i, m_originData);

		// 위에서 부터 다시 힙 구성을 해나가기
		int parent = 0;
		int curr = 1;
		do
		{
			curr = 2 * parent + 1;
			// 자식 중에 더 큰 값을 찾기
			if (curr < i - 1 && m_originData[curr] < m_originData[curr + 1])
			{
				++curr;
			}

			// 부모보다 자식이 크다면 교환
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

void Sorter::MergeSort_Impl(int start, int middle, int end, std::vector<int>& tempArr)
{
	int i = start;		// 절반 나눈 후 좌측 index
	int j = middle + 1;	// 절반 나눈 후 우측 index
	int k = start;	// 정렬한 새 배열에 담을 때 쓰는 index

	while (i <= middle && j <= end)
	{
		// i 칸과 j 칸 비교해서 작은 녀석을 정렬하는 배열에 복사함
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

	// i 나 j 에서 범위를 벗어났다면, 남은 나머지는 그냥 순서대로 복사해서 넣으면 됨
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

	// 정렬한 데이터를 원본 배열에 삽입
	for (int t = start; t <= end; ++t)
	{
		m_originData[t] = tempArr[t];
	}
}

void Sorter::MergeSort(int start, int end, std::vector<int>& tempArr)
{
	if (start < end)	// 이거 이외의 경우라면 원소 갯 수가 1개인 경우임
	{
		int middle = (start + end) / 2;
		MergeSort(start, middle, tempArr);
		MergeSort(middle + 1, end, tempArr);
		MergeSort_Impl(start, middle, end, tempArr);
	}
}
