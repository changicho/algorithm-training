#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  bool canCross(vector<int>& stones) {
    int size = stones.size();
    vector<unordered_set<int>> dp(size);

    unordered_map<int, int> indexes;
    for (int i = 0; i < size; i++) {
      int cur = stones[i];
      indexes[cur] = i;
    }

    if (stones[1] - stones[0] == 1) {
      dp[1].insert(1);
    }
    for (int i = 1; i < size; i++) {
      int cur = stones[i];

      for (int step : dp[i]) {
        for (int diff = -1; diff <= 1; diff++) {
          int next = cur + step + diff;

          if (indexes.count(next) && i < indexes[next]) {
            int target = indexes[next];
            dp[target].insert(step + diff);
          }
        }
      }
    }

    return dp.back().size() > 0;
  }
};