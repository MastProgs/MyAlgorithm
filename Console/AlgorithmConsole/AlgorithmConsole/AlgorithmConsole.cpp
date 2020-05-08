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
			// std::random_shuffle(v.begin(), v.end());	// 완전 무작위가 아님 + C++17 부터는 삭제됨
		};

		auto PrintVector = [](std::vector<int>& v)
		{
			std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
			std::cout << "\n";
		};

		std::vector<int> v;
		for (size_t i = 0; i < 10; i++)
		{
			v.emplace_back(i + 1);
		}

		Sorter sorter{ v };
		RefreshVector(v);
		//PrintVector(v);
		{
			// 시간복잡도는 O(N^2) - 왜냐하면 각 원소별로 순환하면서 찾기 때문에, N*(N+1)/2 번 순환을 함
			std::cout << "\nSelection Sort : ";
			ScopedTimer t{ false };
			sorter.DoSelectionSort();
		}
		//PrintVector(v);

		RefreshVector(v);
		//PrintVector(v);
		{
			// 시간복잡도는 O(N^2) - 버블정렬은 선택정렬에 비해 양쪽 읽고 쓰기를 더 해서, 실제론 선택 정렬보다 더 느림
			std::cout << "\nBubble Sort : ";
			ScopedTimer t{ false };
			sorter.DoBubbleSort();
		}
		//PrintVector(v);

		RefreshVector(v);
		//PrintVector(v);
		{
			// 시간복잡도는 O(N^2) - 정렬이 거의 되어 있는 경우 N-1 번을 모두 순회하지 않기 때문에, 선택 및 버블보단 성능이 올라가게 된다
			std::cout << "\Insertion Sort : ";
			ScopedTimer t{ false };
			sorter.DoInsertionSort();
		}
		//PrintVector(v);

		RefreshVector(v);
		//PrintVector(v);
		{
			// 시간복잡도는 O(N * log N) - 입력하는 데이터가 정렬되어 최악의 경우가 발생 할 때 O(N^2)
			std::cout << "\Quick Sort : ";
			ScopedTimer t{ false };
			sorter.DoQuickSort();
		}
		//PrintVector(v);

		RefreshVector(v);
		//PrintVector(v);
		{
			std::cout << "\Quick Sort : ";
			ScopedTimer t{ false };
			sorter.DoReversQuickSort();
		}
		//PrintVector(v);

#pragma region STLsort
		RefreshVector(v);
		//PrintVector(v);
		{
			std::cout << "\STL Sort : ";
			ScopedTimer t{ false };
			std::sort(v.begin(), v.end(), [](int lhs, int rhs) { return lhs > rhs; });
		}
		//PrintVector(v);
#pragma endregion STLsort
	}
#pragma endregion Sort

}