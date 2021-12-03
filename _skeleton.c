#include <stdio.h>

int main(void)
{
    static const int MAX_NAME_LENGTH = 8;

    int total_age = 0;

    char name[MAX_NAME_LENGTH];
    int age;

    while (scanf("%s %d", name, &age) > 0)
    {
        total_age += age;
    }

    printf("total_age: %d\n", total_age);
}
