#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use min max
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  int minimumArea(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    int minY = INT_MAX, maxY = INT_MIN;
    int minX = INT_MAX, maxX = INT_MIN;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 1) {
          minY = min(minY, y);
          maxY = max(maxY, y);

          minX = min(minX, x);
          maxX = max(maxX, x);
        }
      }
    }

    int height = maxY - minY + 1;
    int width = maxX - minX + 1;

    return height * width;
  }
};