#pragma once

#include <vector>

class KruskalDistance
{
public:
	KruskalDistance() = delete;
	KruskalDistance(int d, int lhs, int rhs) : distance{ d }, lhsNode{ lhs }, rhsNode{ rhs }{};
	~KruskalDistance() = default;

	bool operator<(const KruskalDistance& k)
	{
		return distance < k.distance;
	}

	int lhsNode;
	int rhsNode;
	int distance;
};

class Kruskal
{
public:
	Kruskal();

	void Initialize();
	void GetSum();

	int GetParent(int index);
	void UnionParent(int l, int r);
	bool IsSameParent(int l, int r);
private:
	std::vector<KruskalDistance> m_distanceList;
	std::vector<int> m_parent;
};

