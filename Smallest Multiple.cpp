// https://projecteuler.net/problem=5

#include <iostream>
#include <vector>

int square(int n)
{
	return n * n;
}

bool is_prime(int p) // brute force check if p>1 is prime for small p
{
	if (p == 2)
		return true;

	for (int i = 2; i < (p / 2)+1; i++)
	{
		if (p % i == 0)
			return false;
	}

	return true;
}

std::vector<int> collect_factors(int n)    // collect minimal set of prime factors of every number from 2 to n
{										   // eg. collect_factors(4) returns {2, 2, 3}
	static std::vector<int> factors = { }; //     collect_factors(6) returns {2, 2, 3, 5}

	for (int i = 2; i <= n; ++i)
	{
		if (is_prime(i))
		{
			factors.push_back(i);
			int powers = square(i);
			while (powers <= n)
			{
				factors.push_back(i);
				powers *= i;
			}
		}
	}

	return factors;
}

int main()
{
	int n = 20;

	std::vector<int> factors = collect_factors(n);
	int product = 1;

	for (int factor : factors)
		product *= factor;

	std::cout << "smallest number divisible by all numbers from 1 to " << n << " is " << product << '\n';

	return 0;
}