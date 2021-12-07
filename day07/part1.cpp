#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

int main(void)
{
    std::vector<int> crab_locations;

    std::string s;
    std::stringstream sstr(s);

    while (std::getline(std::cin, s, ','))
    {
        crab_locations.push_back(std::stoi(s));
    }

    int median_location = crab_locations.size() / 2;
    std::nth_element(crab_locations.begin(), crab_locations.begin() + median_location, crab_locations.end());
    int median = crab_locations[median_location];

    long total_distance = 0;

    for (auto i : crab_locations)
    {
        total_distance += abs(i - median);
    }

    std::cout << "location: " << median << ", total distance: " << total_distance << '\n';
}
