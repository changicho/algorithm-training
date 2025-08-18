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

// use binary decomposition
// time : O(Q * log_2(N))
// space : O(log_2(N))
class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    const int MOD = 1e9 + 7;

    vector<int> powers;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) {
        powers.push_back(1 << i);
      }
    }

    vector<int> answer;
    for (vector<int>& q : queries) {
      int left = q[0], right = q[1];

      long long cur = 1;
      for (int i = left; i <= right; i++) {
        cur *= powers[i];
        cur %= MOD;
      }

      answer.push_back(cur);
    }
    return answer;
  }
};

// use binary decomposition & precalculation
// time : O(Q + (log_2(N))^2)
// space : O(log_2(N))
class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    const int MOD = 1e9 + 7;

    vector<int> powers;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) {
        powers.push_back(1 << i);
      }
    }

    int size = powers.size();
    int dp[32][32] = {
        0,
    };

    for (int left = 0; left < size; left++) {
      long long cur = 1;
      for (int right = left; right < size; right++) {
        cur *= powers[right];
        cur %= MOD;
        dp[left][right] = cur;
      }
    }

    vector<int> answer;
    for (vector<int>& q : queries) {
      int left = q[0], right = q[1];

      long long cur = dp[left][right];

      answer.push_back(cur);
    }
    return answer;
  }
};