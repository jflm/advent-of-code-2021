#include <iostream>
#include <numeric>
#include <cmath>
#include <forward_list>
#include <string>

int size_of(std::forward_list<std::string> &l);

int btod(std::string &binary, int len);

int filter_winners(std::forward_list<std::string> rows, int len, bool invert);

int main(void)
{

    static const int NUM_BITS = 12;

    std::string n;
    std::forward_list<std::string> rows;

    while (std::cin >> n)
        rows.emplace_front(n);

    int o2_rating = filter_winners(rows, NUM_BITS, false);
    int co2_rating = filter_winners(rows, NUM_BITS, true);

    std::cout << "o2: " << o2_rating << ", co2: " << co2_rating << ", product: " << o2_rating * co2_rating << std::endl;
}

int filter_winners(std::forward_list<std::string> rows, int len, bool invert)
{
    int out = 0;
    for (int i = 0; i < len; i++)
    {

        if (size_of(rows) == 1)
            return btod(rows.front(), len);

        int ones = 0;
        int zeroes = 0;
        for (auto v : rows)
            v[i] == '0' ? zeroes++ : ones++;

        out <<= 1;

        if (!invert)
        {
            if (ones >= zeroes)
            {
                out += 1;
                std::erase_if(rows, [i](std::string str)
                              { return str[i] == '0'; });
            }
            else
            {
                std::erase_if(rows, [i](std::string str)
                              { return str[i] == '1'; });
            }
        }
        else
        {
            if (ones >= zeroes)
            {
                std::erase_if(rows, [i](std::string str)
                              { return str[i] == '1'; });
            }
            else
            {
                out += 1;
                std::erase_if(rows, [i](std::string str)
                              { return str[i] == '0'; });
            }
        }
    }
    return out;
}

int btod(std::string &binary, int len)
{
    int out = 0;
    for (int i = 0; i < len; i++)
    {
        out <<= 1;
        int num = binary[i] - 48;
        out += num;
    }
    return out;
}

int size_of(std::forward_list<std::string> &l)
{
    int c = 0;
    for (auto i : l)
        c++;
    return c;
}
