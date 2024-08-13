// https://projecteuler.net/problem=2

#include <iostream>

int fibonacci(int n) // starting with 1 and 2, nth fibonacci number f_n = f_{n-1} + f_{n-2}
{
	int f_1 = 1;
	int f_2 = 1;

	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);

}

int main()
{

	int even_fib_sum = 0;
	int n = 1;
	int f_n = 1;

	while (f_n <= 4000000)
	{
		if (f_n % 2 == 0)
		{
			even_fib_sum += f_n;
		}
		n++;
		f_n = fibonacci(n);
	}

	std::cout << "sum of even fibonacci not exceeding 4 million is " << even_fib_sum << '\n';


	return 0;
}
