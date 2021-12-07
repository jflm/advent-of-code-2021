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

    int total = 0;
    int count = 0;
    while (std::getline(std::cin, s, ','))
    {
        int val = std::stoi(s);
        crab_locations.push_back(val);
        total += val;
        count++;
    }
    int mean = total / count;

    long min = __LONG_MAX__;
    int res = -1;
    // search +/-5 each side of the mean
    int cand = mean;
    int updown = -1;
    int c = 0;
    // use this to break out of the loop if we find higher values both sides of whatever is currently min
    int prev_was_higher = 0;
    while (cand > mean - 5 && cand < mean + 5)
    {
        updown *= -1;

        long dist = 0;
        for (auto i : crab_locations)
        {
            long d = abs(i - cand);
            long tri = (d * (d + 1)) / 2;
            dist += tri;
        }

        if (dist < min)
        {
            min = dist;
            res = cand;
        }
        else
            prev_was_higher++;

        if (prev_was_higher >= 2)
            break;

        cand += (updown * ++c);
    }

    std::cout << "found min fuel: " << min << " for location: " << res << '\n';
}
