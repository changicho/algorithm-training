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
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    int size = nums.size();

    int odd = 0, even = 0, toggled = 0, prev = -1;
    for (int& num : nums) {
      if (num % 2 == 1) {
        odd++;
      } else {
        even++;
      }

      if (num % 2 != prev % 2) {
        toggled++;
        prev = num;
      }
    }
    return max({odd, even, toggled});
  }
};

// use pattern check
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    int answer = 0;
    vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (vector<int>& p : patterns) {
      int count = 0;

      for (int& num : nums) {
        if (num % 2 == p[count % 2]) {
          count++;
        }
      }
      answer = max(answer, count);
    }
    return answer;
  }
};

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    int size = nums.size();

    int oddCount = 0, evenCount = 0;

    int dp[200001][2] = {
        0,
    };

    for (int i = 1; i <= size; i++) {
      int cur = nums[i - 1];
      if (cur % 2 == 1) {
        oddCount++;
      } else {
        evenCount++;
      }

      dp[i][1] = dp[i - 1][1];
      dp[i][0] = dp[i - 1][0];

      dp[i][cur % 2] = max(dp[i][cur % 2], dp[i - 1][(cur + 1) % 2] + 1);
    }

    return max({evenCount, oddCount, dp[size][0], dp[size][1]});
  }
};