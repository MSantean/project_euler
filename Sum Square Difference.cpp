#include <iostream>

int square(int x)
{
	return x * x;
}

int main()
{
	int sum_of_squares = 0;
	int square_of_sums = 0;

	for (int i = 1; i < 101; ++i)
	{
		sum_of_squares += square(i);
		square_of_sums += i;
	}

	square_of_sums = square(square_of_sums);

	std::cout << "Difference between the square of the sums and the sum of the squares of the first 100 natural numbers is " << square_of_sums - sum_of_squares << '\n';

	return 0;
}