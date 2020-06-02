#pragma once
#include <vector>
class Fibonacci
{
public:
	Fibonacci() = delete;
	Fibonacci(size_t n);

	size_t GetValue(size_t n);

	void Print();
private:
	size_t m_number{ 0 };
	std::vector<size_t> m_memo;
};

