#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

// naive recursive approach to start with
long count_fish(std::vector<int> *fishes, int days, int elapsed_days)
{
    if (days == 0)
    {
        return fishes->size();
    }

    for (int i = 0; i < fishes->size(); i++)
    {
        if (fishes->at(i) == elapsed_days)
        {
            fishes->at(i) += 7;
            fishes->push_back(elapsed_days + 9);
        }
    }

    return count_fish(fishes, days - 1, elapsed_days + 1);
}

int main(void)
{
    typedef int fish;
    std::string input;
    std::vector<fish> fishes;

    while (std::cin >> input)
    {
        for (auto c : input)
        {
            if (c != ',')
            {
                fishes.push_back(c - 48); // horrible hack, i love it
            }
        }
    }

    long fish_count = count_fish(&fishes, 80, 0);
    std::cout << "count: " << fish_count << std::endl;
}
