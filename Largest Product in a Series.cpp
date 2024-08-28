// https://projecteuler.net/problem=8

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int get_digit(char c) // converts digit character to integer (eg. get_digit('0') = 0)
{
	return int(c) - 48;
}

long long vector_product(std::vector<int> vector) // returns product of elements of vector
{
	long long product = 1;

	for (int v : vector)
		product *= v;

	return product;
}

int main()
{
	std::ifstream my_file ("1000_digit_number.txt"); // 1000 digit number stored in 20 lines of 50 characters each
	std::string line;
	std::vector<int> digits = { };

	if (my_file.is_open()) // read each digit as a separate integer into vector digits
	{
		while (getline(my_file, line))
		{
			for (int i = 0; i < 50; i++)
				digits.push_back(get_digit((line[i])));
			
		}
		my_file.close();
	}

	long long max = 0;
	std::vector<int> max_digits = { };

	for (int i = 0; i < 1000 - 13; i++)
	{                                   
		if (vector_product(std::vector<int>(digits.begin() + i, digits.begin() + i + 13)) > max)
		{
			max = vector_product(std::vector<int>(digits.begin() + i, digits.begin() + i + 13));
			max_digits = std::vector<int>(digits.begin() + i, digits.begin() + i + 13);
		}
	}

	std::cout << "The digits are: ";

	for (int digit : max_digits)
		std::cout << digit << ' ';

	std::cout << '\n' << "Max product of 13 adjacent digits is " << vector_product(max_digits) << '\n';


	return 0;
}