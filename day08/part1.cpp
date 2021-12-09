#include <iostream>
#include <sstream>
#include <string>

int main(void) {
  int known[10]{0, 0, 1, 7, 4, 0, 0, 8, 0, 0};

  int count = 0;
  std::string s;

  while (std::getline(std::cin, s, '\n')) {
    bool is_output = false;
    std::stringstream sstr(s);
    std::string elem;

    while (std::getline(sstr, elem, ' ')) {
      if (is_output && known[elem.length()]) {
        count++;
      }
      if (elem == "|") {
        is_output = true;
      }
    }
  }

  std::cout << "count: " << count << "\n";
}
