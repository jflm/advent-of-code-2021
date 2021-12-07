#include <iostream>
#include <string>
#include <sstream>

int main(void)
{

    // for numbers on individual lines
    int n;
    int total = 0;
    while (std::cin >> n)
    {
        total += n;
    }

    // for comma-separated numbers on a single line
    std::string s;
    std::stringstream sstr(s);
    while (std::getline(std::cin, s, ','))
    {
        total += std::stoi(s);
    }
}
