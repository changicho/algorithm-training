#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// use dynamic programming
// time : O(N^2 + N * log_2(N))
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    unordered_map<int, int> dp;
    sort(arr.begin(), arr.end());

    for (int &num : arr) {
      dp[num]++;
    }

    for (int i = 0; i < arr.size(); i++) {
      int num = arr[i];

      for (int leftI = 0; leftI < i; leftI++) {
        int left = arr[leftI];
        int right = num / left;

        if (left * right != num) continue;
        if (dp.count(right) == 0) continue;

        dp[num] += ((long long)dp[left] * dp[right]) % MOD;
        dp[num] %= MOD;
      }
    }

    int answer = 0;
    for (auto &it : dp) {
      answer += it.second;
      answer %= MOD;
    }
    return answer;
  }
};