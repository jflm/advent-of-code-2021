#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// find chars in str1 that are not in str2
std::string strcompl(std::string str1, std::string str2) {
  std::string out;
  for (auto c : str1) {
    if (str2.find(c) == std::string::npos) {
      out += c;
    }
  }
  return out;
}

// check if all chars in str1 are in str2
bool findinstr(std::string str1, std::string str2) {
  for (int i = 0; i < str1.length(); i++) {
    if (str2.find(str1[i]) == std::string::npos) {
      return false;
    }

    if (i == str1.length() - 1) {
      return true;
    }
  }
  return false;
}

// check if exactly one char from str1 exists in str2
bool findoneinstr(std::string str1, std::string str2) {
  int found = 0;
  for (int i = 0; i < str1.length(); i++) {
    if (str2.find(str1[i]) != std::string::npos) {
      found++;
      if (found > 1) {
        return false;
      }
    }
  }
  return found == 1;
}

bool sort_by_length(std::string a, std::string b) {
  return a.length() < b.length();
}

class DiscoveredValues {
 public:
  std::string find_combination(int i) { return intstr[i]; }
  int get_value(std::string str) { return strint[str]; }
  void set(std::string str, int i) {
    strint[str] = i;
    intstr[i] = str;
  }

 private:
  std::map<std::string, int> strint;
  std::map<int, std::string> intstr;
};

int main(void) {
  int known[10]{0, 0, 1, 7, 4, 0, 0, 8, 0, 0};

  long total = 0;
  std::string s;

  int cnt = 0;

  while (std::getline(std::cin, s, '\n')) {
    bool is_output = false;
    DiscoveredValues values;

    std::stringstream sstr(s);
    std::string elem;

    std::vector<std::string> signal;
    std::vector<std::string> output;

    while (std::getline(sstr, elem, ' ')) {
      std::sort(elem.begin(), elem.end());

      if (elem == "|") {
        is_output = true;
        continue;
      }

      if (!is_output) {
        signal.push_back(elem);
      }

      if (is_output) {
        output.push_back(elem);
      }
    }

    std::sort(signal.begin(), signal.end(), sort_by_length);

    std::string rhs = "zzz";
    std::string lhs = "zzz";

    for (auto elem : signal) {
      int k = known[elem.length()];
      if (k) {
        values.set(elem, k);
        if (k == 1) {
          rhs = elem;
        }
      }
    }

    for (auto elem : signal) {
      if (elem.length() == 5) {
        if (findinstr(rhs, elem)) {
          values.set(elem, 3);
          lhs = strcompl(values.find_combination(8), elem);
        } else {
          if (strcompl(elem, values.find_combination(4)).length() == 2) {
            // if elem contains exactly 2 chars that are not in 4 it must be 5
            values.set(elem, 5);
          } else {
            // if elem contains exactly 4 chars that are not in 4 it must be 2
            values.set(elem, 2);
          }
        }
      }

      if (elem.length() == 6) {
        if (findinstr(rhs, elem) && findinstr(lhs, elem)) {
          values.set(elem, 0);
        } else if (findoneinstr(rhs, elem)) {
          values.set(elem, 6);
        } else {
          values.set(elem, 9);
        }
      }
    }

    std::string num;
    for (auto elem : output) {
      int n = values.get_value(elem);
      num += std::to_string(n);
    }

    total += std::stoi(num);
  }

  std::cout << "total: " << total << "\n";
}
