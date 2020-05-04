#include <iostream>
#include "Timer.h"

int main()
{
	{
		ScopedTimer t;
		std::cout << "Hello World!\n";
	}
}