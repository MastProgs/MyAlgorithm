#include "Kruskal.h"

#include <algorithm>
#include <iostream>

// https://blog.naver.com/ndb796/221230994142

Kruskal::Kruskal()
{
	Initialize();
	GetSum();
}

void Kruskal::Initialize()
{
	m_distanceList.emplace_back(KruskalDistance{ 12, 7, 1 });
	m_distanceList.emplace_back(KruskalDistance{ 13, 7, 4 });
	m_distanceList.emplace_back(KruskalDistance{ 73, 7, 5 });
	m_distanceList.emplace_back(KruskalDistance{ 28, 4, 1 });
	m_distanceList.emplace_back(KruskalDistance{ 67, 2, 1 });
	m_distanceList.emplace_back(KruskalDistance{ 17, 5, 1 });
	m_distanceList.emplace_back(KruskalDistance{ 24, 2, 4 });
	m_distanceList.emplace_back(KruskalDistance{ 62, 2, 5 });
	m_distanceList.emplace_back(KruskalDistance{ 45, 6, 5 });
	m_distanceList.emplace_back(KruskalDistance{ 20, 3, 5 });
	m_distanceList.emplace_back(KruskalDistance{ 37, 3, 6 });

	std::sort(m_distanceList.begin(), m_distanceList.end());

	int maxNodeNum{ 0 };
	for (const auto& d : m_distanceList)
	{
		maxNodeNum = std::max({ maxNodeNum, d.lhsNode, d.rhsNode });
	}

	++maxNodeNum;
	m_parent.reserve(maxNodeNum);
	for (size_t i = 0; i < maxNodeNum; i++)
	{
		m_parent.emplace_back(i);
	}
}

void Kruskal::GetSum()
{
	int sum{ 0 };

	for (const auto& node : m_distanceList)
	{
		if (false == IsSameParent(node.lhsNode, node.rhsNode))
		{
			sum += node.distance;
			UnionParent(node.lhsNode, node.rhsNode);
		}
	}

	std::cout << sum << "\n";
}

int Kruskal::GetParent(int index)
{
	if (m_parent[index] == index) return index;
	return m_parent[index] = GetParent(m_parent[index]);
}

void Kruskal::UnionParent(int l, int r)
{
	l = GetParent(l);
	r = GetParent(r);

	// 더 숫자가 작은 부모로 병합
	if (l < r) m_parent[r] = l;
	else m_parent[l] = r;
}

bool Kruskal::IsSameParent(int l, int r)
{
	l = GetParent(l);
	r = GetParent(r);

	if (l == r) return true;
	else return false;
}
