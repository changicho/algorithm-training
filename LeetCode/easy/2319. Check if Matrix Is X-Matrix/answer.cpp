#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  bool isX(int y, int x, int size) { return x == y || size - 1 - y == x; }

 public:
  bool checkXMatrix(vector<vector<int>>& grid) {
    int size = grid.size();

    for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++) {
        if (isX(y, x, size)) {
          if (grid[y][x] == 0) return false;
        } else {
          if (grid[y][x] != 0) return false;
        }
      }
    }
    return true;
  }
};