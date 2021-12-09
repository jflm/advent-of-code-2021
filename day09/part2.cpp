#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

int main(void) {
  std::string s;
  std::vector<std::vector<int>> mat;

  while (std::getline(std::cin, s, '\n')) {
    std::vector<int> m;
    for (auto c : s) {
      if (c - 48 < 9) {
        m.push_back(-1);
      } else {
        m.push_back(0);
      }
    }
    mat.push_back(m);
  }

  int basin_id = 0;
  std::map<int, int> basins;

  for (int row = 0; row < mat.size(); row++) {
    for (int col = 0; col < mat[0].size(); col++) {
      if (mat[row][col] >= 0) {
        continue;
      }

      basin_id++;

      std::pair<int, int> node;
      std::queue<std::pair<int, int>> Q;
      Q.push(std::make_pair(row, col));

      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        int r = node.first;
        int c = node.second;
        if (mat[r][c] < 0) {
          mat[r][c] = basin_id;
          basins[basin_id]++;

          if (r > 0) Q.push(std::make_pair(r - 1, c));                  // up
          if (r < mat.size() - 1) Q.push(std::make_pair(r + 1, c));     // down
          if (c > 0) Q.push(std::make_pair(r, c - 1));                  // left
          if (c < mat[0].size() - 1) Q.push(std::make_pair(r, c + 1));  // right
        }
      }
    }
  }

  std::map<int, int>::iterator it;
  int pos1 = 0, pos2 = 0, pos3 = 0;
  for (it = basins.begin(); it != basins.end(); it++) {
    if (it->second > pos1) {
      pos3 = pos2;
      pos2 = pos1;
      pos1 = it->second;
    } else if (it->second > pos2) {
      pos3 = pos2;
      pos2 = it->second;
    } else if (it->second > pos3) {
      pos3 = it->second;
    }
  }

  std::cout << "product: " << pos1 * pos2 * pos3 << '\n';
}
