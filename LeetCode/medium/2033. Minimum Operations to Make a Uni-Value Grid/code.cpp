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
  int minOperations(vector<vector<int>> &grid, int x) {
    int rows = grid.size(), cols = grid[0].size();
    unordered_set<int> mods;

    vector<int> nums;

    for (vector<int> &row : grid) {
      for (int &num : row) {
        mods.insert(num % x);
        nums.push_back(num);
      }
    }

    if (mods.size() >= 2) return -1;

    sort(nums.begin(), nums.end());

    int target = nums[nums.size() / 2];
    int answer = 0;
    for (vector<int> &row : grid) {
      for (int &num : row) {
        answer += abs(target - num) / x;
      }
    }

    return answer;
  }
};