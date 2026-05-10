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

// use brute force
// time : O(RC)
// space : O(R + C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

 public:
  vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int rows = grid.size(), cols = grid[0].size();

    int limit = min(rows, cols) / 2;
    for (int i = 0; i < limit; i++) {
      int length = (rows - i * 2) * 2 + (cols - i * 2) * 2 - 4;

      int moveCount = k % length;

      int ys = i, ye = rows - 1 - i;
      int xs = i, xe = cols - 1 - i;

      vector<Axis> targets;
      vector<int> nums;
      for (int y = ys; y <= ye; y++) {
        targets.push_back({y, xs});
        nums.push_back(grid[y][xs]);
      }
      for (int x = xs + 1; x <= xe; x++) {
        targets.push_back({ye, x});
        nums.push_back(grid[ye][x]);
      }
      for (int y = ye - 1; y >= ys; y--) {
        targets.push_back({y, xe});
        nums.push_back(grid[y][xe]);
      }
      for (int x = xe - 1; x >= xs + 1; x--) {
        targets.push_back({ys, x});
        nums.push_back(grid[ys][x]);
      }

      vector<int> newNums(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        newNums[(i + moveCount) % length] = nums[i];
      }

      for (int i = 0; i < newNums.size(); i++) {
        grid[targets[i].y][targets[i].x] = newNums[i];
      }
    }

    return grid;
  }
};