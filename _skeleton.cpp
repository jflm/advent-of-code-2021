#include <iostream>

int main(void) {

    // adds up all the numbers coming in from stdin
    int n;
    int total = 0;
    while (std::cin >> n) {
        total += n;
    }

    std::cout << "total: " << total << std::endl;

}

