#include <iostream>

int main(void)
{
    int n;
    int prev = INT16_MAX;
    int increases = 0;
    while (std::cin >> n)
    {
        if (n > prev)
        {
            increases++;
        }
        prev = n;
    }

    std::cout << "increases: " << increases << std::endl;
}
