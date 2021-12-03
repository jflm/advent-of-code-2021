#include <stdio.h>

int main(void)
{
    static const int NUM_BITS = 12;

    char row[NUM_BITS + 1];

    long total_rows = 0;
    long columns[NUM_BITS] = {0};

    while (scanf("%s", row) > 0)
    {
        for (int i = 0; i < NUM_BITS; i++)
            columns[i] += (row[i] - 48);

        total_rows++;
    }

    int gamma = 0, epsilon = 0;

    for (int i = 0; i < NUM_BITS; i++)
    {
        gamma <<= 1;
        epsilon <<= 1;

        int most_common = columns[i] > total_rows / 2;
        gamma += most_common;
        epsilon += !most_common;
    }

    printf("gamma: %d, epsilon: %d, product: %d\n", gamma, epsilon, gamma * epsilon);
}
