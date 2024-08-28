// https://projecteuler.net/problem=9

#include <iostream>

/*

PLEASE READ:

a+b+c=1000

a^2 + b^2 = c^2

=> a^2 + 2ab + b^2 = (a+b)^2 > a^2 + b^2 = c^2

=> a+b > c

=> 1000 = a+b+c > 2c

=> c < 500

=> a < b < c < 500 is our bound of search.

*/

int square(int x)
{
	return x * x;
}

bool is_triplet(int a, int b, int c)
{
	return square(a) + square(b) == square(c);
}

int main()
{
	for(int c = 0; c < 500; c++)
		for(int b = 0; b < c; b++)
			for (int a = 0; a < b; a++)
			{
				if (is_triplet(a, b, c) && a + b + c == 1000)
				{
					std::cout << "Our Pythagorean triplet with sum 1000 is " << a << ", " << b << ", " << c << " with product " << a * b * c << '\n';
					break;
				}
			}

	return 0;
}