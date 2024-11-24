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

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> minScore(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<int>> nums;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        nums.push_back({grid[y][x], y, x});
      }
    }

    vector<int> rowVals(rows, 1);
    vector<int> colVals(cols, 1);

    sort(nums.begin(), nums.end());

    for (vector<int>& line : nums) {
      int val = line[0], y = line[1], x = line[2];

      val = max(rowVals[y], colVals[x]);
      grid[y][x] = val;
      rowVals[y] = colVals[x] = val + 1;
    }

    return grid;
  }
};