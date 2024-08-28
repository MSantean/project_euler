// https://projecteuler.net/problem=11

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int char_to_digit(char c)
{
	return int(c) - 48;
}

int main()
{
	std::ifstream my_file("20_by_20_array.txt");

	std::vector<char> v;
	char c;

	while (my_file >> c) // read characters from grid to temporary array
		v.push_back(c);

	my_file.close();

	std::vector<int> entries = { };

	for (int i = 0; i < 800; i++) // convert vector of characters to vector of ints
	{
		if (i % 2 == 0)
		{
			entries.push_back(char_to_digit(v[i]) * 10 + char_to_digit(v[i + 1]));
		}
	}

	int grid[20][20];

	for (int i = 0; i < 20; i++) // convert vector of 400 ints to a true 20x20 grid
		for (int j = 0; j < 20; j++)
		{
			grid[i][j] = entries[i * 20 + j];
		}

	int max = 0;

	// check vertical products

	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 20; j++)
			if (grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j] > max)
				max = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];

	// check horizontal products

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 17; j++)
			if (grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3] > max)
				max = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];

	// check top left to bottom right diagonals

	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 17; j++)
			if (grid[i][j] * grid[i+1][j + 1] * grid[i+2][j + 2] * grid[i+3][j + 3] > max)
				max = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];


	// check bottom left to top right diagonals

	for (int i = 3; i < 20; i++)
		for (int j = 0; j < 17; j++)
			if (grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3] > max)
				max = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3];

	std::cout << "The maximum desired product is " << max << '\n';

	return 0;
}