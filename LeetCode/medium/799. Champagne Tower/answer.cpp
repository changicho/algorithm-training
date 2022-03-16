#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(1) // O(100^2)
// space : O(1) // O(100^2)
class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> tower(101, vector<double>(101, 0));

    int row = 0;
    tower[0][0] = poured;
    for (int y = 0; y < 100; y++) {
      for (int x = 0; x <= y; x++) {
        if (tower[y][x] >= 1) {
          double remain = tower[y][x] - 1;
          tower[y][x] = 1;
          tower[y + 1][x] += remain / 2;
          tower[y + 1][x + 1] += remain / 2;
        }
      }
    }

    return tower[query_row][query_glass];
  }
};