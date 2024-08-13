// https://projecteuler.net/problem=4

#include <iostream>
#include <vector>

int ten_to_power(int n) // returns 10^n with n>0
{
	int product = 1;

	for (int i = 1; i <= n; i++)
		product *= 10;

	return product;
}

std::vector<int> collect_digits(int n) // collect digits of n in a vector
{
	if (n < 10)
		return { n };

	int copy = n;
	std::vector<int> digits = {};

	while (copy % 10 != copy)
	{
		digits.push_back(copy % 10);
		copy = (copy - copy % 10) / 10;
	}
	digits.push_back(copy);

	return digits;
}

bool is_palindrome(int n) // n>=0		
{	
	std::vector<int> digits = collect_digits(n);

	for (int i = 0; i < digits.size() / 2; ++i) // middle digit doesn't matter when digits.size() is odd
	{
		if (digits[i] != digits[digits.size() - 1 - i])
			return false;
	}
	
	return true;
}

int main()
{
	int max = 0;
	int first = 0;
	int second = 0; // collect largest palindrome and its first and second 3-digit factors

	for(int i=999; i>99; i--)
		for(int j=999; j>99; j--)
			if (is_palindrome(i * j) && i*j>max)
			{
				max = i * j;
				first = i;
				second = j;
			}

	std::cout << "Largest palindrome made from product of two 3-digit numbers is " << max << " with product " << first  << " * " << second << '\n';
	
	return 0;
}
