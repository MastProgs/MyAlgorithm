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
