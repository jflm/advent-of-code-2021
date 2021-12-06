#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>
#include <forward_list>

class Board
{
public:
	bool complete = false;
	bool full()
	{
		return count >= 25;
	}
	void put_number(int num)
	{
		if (full())
		{
			// do something
		}
		int row = count / 5;
		int col = count % 5;
		numbers[row][col] = num;
		count++;
	}
	bool mark(int num)
	{
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				if (numbers[row][col] == num)
				{
					// mark it off as -1
					numbers[row][col] = -1;
					// check whole row
					int row_sum = 0;
					for (int i = 0; i < 5; i++)
					{
						row_sum += numbers[row][i];
					}
					if (row_sum == -5)
					{
						return true;
					}
					// check whole col
					int col_sum = 0;
					for (int i = 0; i < 5; i++)
					{
						col_sum += numbers[i][col];
					}
					if (col_sum == -5)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	int remaining_numbers_sum()
	{
		int total = 0;
		for (auto r : numbers)
		{
			for (auto c : r)
			{
				if (c >= 0)
				{
					total += c;
				}
			}
		}
		return total;
	}
	void print()
	{
		for (auto r : numbers)
		{
			for (auto c : r)
			{
				std::cout << c << " ";
			}
			std::cout << std::endl;
		}
	}

private:
	std::array<std::array<int, 5>, 5> numbers;
	int count = 0;
};

int main(void)
{

	bool first_line = true;
	std::string line;
	std::vector<int> drawn_numbers;
	std::forward_list<Board *> boards;

	while (std::cin >> line)
	{
		if (first_line)
		{
			std::string i;
			std::stringstream ss(line);
			while (std::getline(ss, i, ','))
			{
				std::stringstream c(i);
				int x;
				c >> x;
				drawn_numbers.push_back(x);
			}
			first_line = false;
			continue;
		}

		Board *board;
		if (boards.empty())
		{
			board = new Board();
			boards.emplace_front(board);
		}
		else
		{
			board = boards.front();
			if (board->full())
			{
				board = new Board();
				boards.emplace_front(board);
			}
		}

		board->put_number(std::stoi(line));
	}

	for (auto num : drawn_numbers)
	{
		for (auto board : boards)
		{
			if (!board->complete && board->mark(num))
			{
				board->complete = true;
				int remaining = board->remaining_numbers_sum();
				std::cout << "winning num was " << num;
				std::cout << ", board remaining is " << remaining;
				std::cout << ", product: " << num * remaining;
				std::cout << std::endl;
			}
		}
	}
}
