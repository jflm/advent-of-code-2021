#include <stdio.h>

int main(void)
{
    static const int MAX_DIRECTION_LENGTH = 8; // f o r w a r d \0

    int horizontal = 0;
    int depth = 0;

    char direction[MAX_DIRECTION_LENGTH];
    int distance;

    while (scanf("%s %d", direction, &distance) > 0)
    {
        // yes this relies on each direction beginning with a different character, but that holds up so who cares
        if (direction[0] == 'f')
            horizontal += distance;

        if (direction[0] == 'd')
            depth += distance;

        if (direction[0] == 'u')
            depth -= distance;
    }

    printf("horizontal: %d, depth: %d, product: %d\n", horizontal, depth, horizontal * depth);
}
