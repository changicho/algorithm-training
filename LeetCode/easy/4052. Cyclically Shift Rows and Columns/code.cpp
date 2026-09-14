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

using ll = long long;

// brute force (extra space)
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                  vector<int>& rowShift,
                                  vector<int>& colShift) {
    for (int y = 0; y < n; y++) {
      if (rowShift[y] == 0) continue;
      int shift = rowShift[y];

      vector<int> nums;
      for (int x = 0; x < n; x++) {
        nums.push_back(grid[y][x]);
      }

      for (int x = 0; x < n; x++) {
        grid[y][x] = nums[(x + shift) % n];
      }
    }
    for (int x = 0; x < n; x++) {
      if (colShift[x] == 0) continue;
      int shift = colShift[x];

      vector<int> nums;
      for (int y = 0; y < n; y++) {
        nums.push_back(grid[y][x]);
      }

      for (int y = 0; y < n; y++) {
        grid[y][x] = nums[(y + shift) % n];
      }
    }
    return grid;
  }
};

// brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                  vector<int>& rowShift,
                                  vector<int>& colShift) {
    for (int y = 0; y < n; y++) {
      if (rowShift[y] == 0) continue;
      int shift = rowShift[y];

      for (int x = 0; x < n; x++) {
        grid[y][x] += ((grid[y][(x + shift) % n]) % 1000) * 1000;
      }

      for (int x = 0; x < n; x++) {
        grid[y][x] /= 1000;
      }
    }
    for (int x = 0; x < n; x++) {
      if (colShift[x] == 0) continue;
      int shift = colShift[x];

      for (int y = 0; y < n; y++) {
        grid[y][x] += ((grid[(y + shift) % n][x]) % 1000) * 1000;
      }

      for (int y = 0; y < n; y++) {
        grid[y][x] /= 1000;
      }
    }
    return grid;
  }
};