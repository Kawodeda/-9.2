
#include <iostream>
#include <vector>
#include "Binary.h"

bool IsPrime(int number)
{
	if (number < 1)
	{
		throw "The number must be whole";
	}
	if (number == 1)
	{
		return false;
	}

	for (int i = 2; i <= static_cast<int>(number / 2); ++i)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int FoundNextPrime(int from)
{
	while (true)
	{
		++from;
		if (IsPrime(from))
		{
			return from;
		}
	}
}

void FoundNumbers(int n)
{
	std::cout << "All prime natural numbers"
		<< std::endl << "that are palindromes in thier binary form"
		<< std::endl << "and less than " << n << ":\n" << std::endl;

	int num = 2;
	while (num < n)
	{
		Binary binaryNum(num);
		if (binaryNum.IsPalindrom())
		{
			std::cout << "  " << num << " (" << binaryNum.ToString() << ")\n";
		}

		num = FoundNextPrime(num);
	}

	std::cout << std::endl;
}

int main()
{
	std::cout << "n = ";
	int n = 0;
	std::cin >> n;
	std::cout << std::endl;
	FoundNumbers(n);
}
