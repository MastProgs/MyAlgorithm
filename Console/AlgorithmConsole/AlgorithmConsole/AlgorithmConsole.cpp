#include <iostream>

#include <random>
#include <iterator>

#include <vector>

#include "Timer.h"
#include "Sort.h"

int main()
{
	{
		ScopedTimer t{ false };
		std::cout << "Hello World!";
	}

#pragma region Sort
	{
		auto RefreshVector = [](std::vector<int>& v)
		{
			std::random_device rd;
			std::mt19937 g(rd());

			std::shuffle(v.begin(), v.end(), g);
			// std::random_shuffle(v.begin(), v.end());	// 완전 무작위가 아님
		};

		auto PrintVector = [](std::vector<int>& v)
		{
			std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		};

		std::vector<int> v;
		for (size_t i = 0; i < 5000; i++)
		{
			v.emplace_back(i + 1);
		}

		Sorter sorter{ v };
		RefreshVector(v);
		//PrintVector(v);
		{
			// 시간복잡도는 O(N^2) - 왜냐하면 각 원소별로 순환하면서 찾기 때문에, N*(N+1)/2 번 순환을 함
			std::cout << "Selection Sort : ";
			ScopedTimer t{ false };
			sorter.DoSelectionSort();
		}
		//PrintVector(v);
	}
#pragma endregion Sort
}