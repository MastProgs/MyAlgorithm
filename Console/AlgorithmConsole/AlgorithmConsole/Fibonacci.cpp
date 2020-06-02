#include "Fibonacci.h"
#include <iostream>

Fibonacci::Fibonacci(size_t n)
	: m_number{ n }
{
	m_memo.reserve(n + 1);
	m_memo.emplace_back(0);
	m_memo.emplace_back(1);
	m_memo.emplace_back(1);

	GetValue(n);
}

size_t Fibonacci::GetValue(size_t n)
{
	if (n < 3) { return 1; }
	if (n < m_memo.size()) { return m_memo[n]; }
	m_memo.emplace_back(GetValue(n - 1) + GetValue(n - 2));
	return m_memo[n];
}

void Fibonacci::Print()
{
	int i{ 0 };
	for (auto& n : m_memo)
	{
		std::cout << "index[" << i << "] : " << n << std::endl;
		++i;
	}
}
