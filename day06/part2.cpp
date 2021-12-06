#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

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

    std::map<int, long> fish_count_map;

    for (auto f : fishes)
    {
        fish_count_map[f]++;
    }

    for (int day = 0; day < 256; day++)
    {

        long new_fish = 0;
        long regen_fish = 0;
        for (int i = 0; i <= 8; i++)
        {
            if (i == 0)
            {
                new_fish = fish_count_map[0];
                regen_fish = fish_count_map[0];
                fish_count_map[0] = 0;
                continue;
            }

            fish_count_map[i - 1] += fish_count_map[i];
            fish_count_map[i] = 0;
            if (i == 6)
            {
                fish_count_map[6] = regen_fish;
            }
            if (i == 8)
            {
                fish_count_map[8] = new_fish;
            }
        }
    }

    long total = 0;
    for (auto const &kv : fish_count_map)
    {
        total += kv.second;
    }

    std::cout << "count: " << total << std::endl;
}
