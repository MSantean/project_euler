#include <iostream>
#include <vector>

int main()
{	
	int count = 1;
	std::vector<int> primes = { 2 };

	for (int i = 3; count <= 10001; i++)
	{
		bool is_prime = true;

		for (int prime : primes)
		{
			if (i % prime == 0)
			{
				is_prime = false;
				break;
			}
		}

		if (is_prime)
		{
			primes.push_back(i);
			count++;
		}
	}

	std::cout << "The 10001st prime number is " << primes[10000] << '\n';

	return 0;
}