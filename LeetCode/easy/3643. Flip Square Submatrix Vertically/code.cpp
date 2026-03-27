#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// brute force
// time : O(K^2)
// space : O(1)
class Solution {
 public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y,
                                       int k) {
    int cols = grid.size(), rows = grid[0].size();

    for (int i = 0; i < k / 2; i++) {
      for (int j = 0; j < k; j++) {
        int r = x + k - i - 1;
        swap(grid[x + i][y + j], grid[r][y + j]);
      }
    }

    return grid;
  }
};