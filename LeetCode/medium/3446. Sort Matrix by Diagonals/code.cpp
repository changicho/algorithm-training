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

// use one pass
// time : O(N^2 \* log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    for (int y = 0; y < rows; y++) {
      vector<int> nums;
      for (int i = 0; i < cols - y; i++) {
        nums.push_back(grid[y + i][i]);
      }

      sort(nums.begin(), nums.end(), greater<int>());

      for (int i = 0; i < cols - y; i++) {
        grid[y + i][i] = nums[i];
      }
    }

    for (int x = 1; x < cols; x++) {
      vector<int> nums;
      for (int i = 0; i < rows - x; i++) {
        nums.push_back(grid[i][x + i]);
      }

      sort(nums.begin(), nums.end());

      for (int i = 0; i < rows - x; i++) {
        grid[i][x + i] = nums[i];
      }
    }

    return grid;
  }
};