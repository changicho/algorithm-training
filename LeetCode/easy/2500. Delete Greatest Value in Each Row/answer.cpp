#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(R * C * log_2(C))
// space : O(1)
class Solution {
 public:
  int deleteGreatestValue(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();

    for (vector<int>& row : grid) {
      sort(row.begin(), row.end());
    }

    int answer = 0;
    for (int x = 0; x < cols; x++) {
      int target = 0;
      for (int y = 0; y < rows; y++) {
        target = max(target, grid[y].back());
        grid[y].pop_back();
      }
      answer += target;
    }
    return answer;
  }
};