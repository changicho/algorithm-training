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

// use dynamic programming
// time : O(N^2 * M)
// space : O(N^2)
class Solution {
 private:
  struct Data {
    int cost;
    vector<int> path;

    bool operator<(const Data& b) const {
      if (cost != b.cost) return cost < b.cost;
      return path < b.path;
    }
  };

 public:
  vector<int> cheapestJump(vector<int>& coins, int maxJump) {
    int size = coins.size();

    vector<int> answer(size + 1);

    vector<Data> dp(size, {INT_MAX, {}});
    dp[0] = {coins[0], {1}};

    for (int i = 0; i < size; i++) {
      if (dp[i].cost == INT_MAX) continue;

      for (int j = i + 1; j <= i + maxJump; j++) {
        if (j >= size) break;
        if (coins[j] == -1) continue;

        Data next = dp[i];
        next.cost += coins[j];
        next.path.push_back(j + 1);
        dp[j] = min(dp[j], next);
      }
    }

    if (dp.back().cost == INT_MAX) return {};
    return dp.back().path;
  }
};

// use dynamic programming with reverse pass
// time : O(N * M)
// space : O(N)
class Solution {
 public:
  vector<int> cheapestJump(vector<int>& coins, int maxJump) {
    int size = coins.size();

    vector<int> nexts(size, -1);
    vector<long> dp(size, INT_MAX);

    dp[size - 1] = coins[size - 1];
    for (int i = size - 1; i >= 0; i--) {
      for (int j = i + 1; j <= i + maxJump && j < size; j++) {
        if (coins[j] == -1) continue;

        int newCost = dp[j] + coins[i];

        if (dp[i] > newCost) {
          dp[i] = newCost;
          nexts[i] = j;
        }
      }
    }

    vector<int> answer;
    int i = 0;
    while (i != -1) {
      answer.push_back(i + 1);

      i = nexts[i];
    }
    if (answer.back() != size) return {};

    return answer;
  }
};