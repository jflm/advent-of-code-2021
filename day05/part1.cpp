#include <cstdio>
#include <iostream>
#include <map>
#include <array>
#include <algorithm>

int main(void)
{

    typedef std::array<unsigned int, 2> point;
    std::map<point, int> covered_squares;

    unsigned int x1, y1;
    unsigned int x2, y2;

    int max_x = 0;
    int max_y = 0;

    while (scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) > 0)
    {
        if (x1 == x2 || y1 == y2)
        {
            unsigned int from_x = std::min(x1, x2);
            unsigned int to_x = std::max(x1, x2);
            unsigned int from_y = std::min(y1, y2);
            unsigned int to_y = std::max(y1, y2);

            if (to_x > max_x)
            {
                max_x = to_x;
            }

            if (to_y > max_y)
            {
                max_y = to_y;
            }

            for (unsigned int x = from_x; x <= to_x; x++)
            {
                for (unsigned int y = from_y; y <= to_y; y++)
                {
                    point p = {x, y};
                    covered_squares[p] += 1;
                }
            }
        }
    }

    std::cout << "max x,y: " << max_x << "," << max_y << std::endl;

    int overlaps = 0;
    for (unsigned int x = 0; x <= max_x; x++)
    {
        for (unsigned int y = 0; y <= max_y; y++)
        {
            point p = {x, y};
            if (covered_squares[p] >= 2)
            {
                overlaps++;
            }
        }
    }

    std::cout << "overlaps: " << overlaps << std::endl;
}
