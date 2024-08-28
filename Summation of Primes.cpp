// https://projecteuler.net/problem=10

#include <iostream>
#include <vector>

long long vector_sum(std::vector<int> vector)
{
	long long sum = 0;

	for (int v : vector)
		sum += v;

	return sum;
}

int main()
{
	const int N = 2000000;

	std::vector<int> primes(N,0);

	for (int i = 0; i < N; i++) // fill "primes" with every number from 0 to N-1
		primes[i] = i;

	for (int p = 2; p < N/2; p++) // mark every multiple of p as 0 starting from p=2
	{
		for (int n = 2; n * p < N; n++)
			primes[n * p] = 0;
	}

	std::cout << "Sum of primes below " << N << " is " << vector_sum(primes) - 1 << '\n'; // subtract one because "primes" vector includes 1

	return 0;
}