#include <stdio.h>

int main(void)
{
    static const int MAX_DIRECTION_LENGTH = 8; // 'f o r w a r d \0'

    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    char direction[MAX_DIRECTION_LENGTH];
    int distance;

    while (scanf("%s %d", direction, &distance) > 0)
    {
        if (direction[0] == 'f')
        {
            horizontal += distance;
            depth += (aim * distance);
        }

        if (direction[0] == 'd')
            aim += distance;

        if (direction[0] == 'u')
            aim -= distance;
    }

    printf("horizontal: %d, depth: %d, product: %d\n", horizontal, depth, horizontal * depth);
}
