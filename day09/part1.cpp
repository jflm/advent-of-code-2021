#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(void) {
  std::string s;
  std::vector<std::vector<int>> mat;

  while (std::getline(std::cin, s, '\n')) {
    std::vector<int> m;
    for (auto c : s) {
      m.push_back(c - 48);
    }
    mat.push_back(m);
  }

  std::vector<int> risk;

  for (int row = 0; row < mat.size(); row++) {
    for (int col = 0; col < mat[0].size(); col++) {
      int n = mat[row][col];
      int up = row > 0 ? mat[row - 1][col] : 10;
      int down = row < mat.size() - 1 ? mat[row + 1][col] : 10;
      int left = col > 0 ? mat[row][col - 1] : 10;
      int right = col < mat[0].size() - 1 ? mat[row][col + 1] : 10;
      if (n < up && n < down && n < left && n < right) {
        risk.push_back(n + 1);
      }
    }
  }

  int total = 0;
  for (auto n : risk) {
    total += n;
  }

  std::cout << "total: " << total << '\n';
}
