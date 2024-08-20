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
// time : O(N)
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int countOfPairs(vector<int>& nums) {
    int size = nums.size();
    // [index][cur]
    int dp[2001][51] = {
        0,
    };

    for (int cur = 0; cur <= nums[0]; cur++) {
      dp[0][cur] = 1;
    }

    for (int i = 1; i < size; i++) {
      for (int before = 0; before <= nums[i - 1]; before++) {
        int beforeDesc = nums[i - 1] - before;

        if (dp[i - 1][before] == 0) continue;

        for (int cur = before; cur <= nums[i]; cur++) {
          int curDesc = nums[i] - cur;

          if (beforeDesc < curDesc) continue;
          dp[i][cur] += dp[i - 1][before];
          dp[i][cur] %= MOD;
        }
      }
    }

    int answer = 0;
    for (int first = 0; first <= nums[size - 1]; first++) {
      answer += dp[size - 1][first];
      answer %= MOD;
    }
    return answer;
  }
};