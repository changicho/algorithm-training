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
// time : O(RC * K^2)
// space : O(K^2 * log_2(K^2))
class Solution {
 public:
  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<int>> answer;
    for (int y = 0; y <= rows - k; y++) {
      vector<int> answerRow;
      for (int x = 0; x <= cols - k; x++) {
        vector<int> nums;
        for (int i = 0; i < k; i++) {
          for (int j = 0; j < k; j++) {
            nums.push_back(grid[y + i][x + j]);
          }
        }

        int cur = INT_MAX;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 1; i++) {
          if (nums[i] == nums[i + 1]) continue;
          int diff = abs(nums[i] - nums[i + 1]);

          cur = min(cur, diff);
        }

        if (cur == INT_MAX) cur = 0;

        answerRow.push_back(cur);
      }

      answer.push_back(answerRow);
    }
    return answer;
  }
};