#include <iostream>

int largest_prime_factor(long long int n) // returns largest prime factor of n
{
	static int f = 2;

	while(f*f<=n)   // fundamental theorem of arithmetic
	{				// when f*f is greater than n we are done as we have already checked all prime factors below f
		if (n % f == 0)
			return largest_prime_factor(n / f);
		f++;
	}

	return n; // when loop condition fails, remaining n will be the largest prime factor

}

int main()
{

	long long int N = 600851475143;

	std::cout << "Largest prime factor of " << N << " is " << largest_prime_factor(N) << '\n';

	return 0;
}