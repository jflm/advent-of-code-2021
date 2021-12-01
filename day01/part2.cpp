#include <iostream>
#include <vector>
#include <numeric>

int main(void)
{
    int n;
    std::vector<int> buf;
    int increases = 0;
    int previous = INT16_MAX;
    while (std::cin >> n)
    {
        if (buf.size() >= 3)
        {
            buf.pop_back();
        }

        buf.insert(buf.begin(), n);

        if (buf.size() == 3) // only operate in the sliding window
        {
            int sum = std::accumulate(buf.begin(), buf.end(), decltype(buf)::value_type(0));
            if (sum > previous)
            {
                increases++;
            }
            previous = sum;
        }
    }

    std::cout << "increases: " << increases << std::endl;
}
