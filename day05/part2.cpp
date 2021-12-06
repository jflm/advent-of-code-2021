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
        int x_direction = x1 == x2 ? 0 : (x2 > x1 ? 1 : -1);
        int y_direction = y1 == y2 ? 0 : (y2 > y1 ? 1 : -1);

        int upper_x = std::max(x1, x2);
        int upper_y = std::max(y1, y2);

        if (upper_x > max_x)
            max_x = upper_x;

        if (upper_y > max_y)
            max_y = upper_y;

        for (int x = x1, y = y1; (x_direction == 0 || x != x2 + x_direction) && (y_direction == 0 || y != y2 + y_direction);)
        {
            point p = {x, y};
            covered_squares[p] += 1;
            x += x_direction;
            y += y_direction;
        }
    }

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
