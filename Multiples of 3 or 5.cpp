// https://projecteuler.net/problem=1

#include <iostream>

int main()
{
	int sum = 0;
	int n = 1000;

	for (int i = 3; i < n; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	std::cout << "sum of multiples of 3 or 5 below " << n << " is " << sum << '\n';

	return 0;
}
