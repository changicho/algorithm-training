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

// 2D prefix sum (inplace)
// time : O(RC)
// space : O(1)
class Solution {
 public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int rows = grid.size(), cols = grid[0].size();

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (y > 0) {
          grid[y][x] += grid[y - 1][x];
        }
        if (x > 0) {
          grid[y][x] += grid[y][x - 1];
        }
        if (y > 0 && x > 0) {
          grid[y][x] -= grid[y - 1][x - 1];
        }

        if (grid[y][x] <= k) {
          answer++;
        }
      }
    }
    return answer;
  }
};