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

// use dynamic programming (bottom up)
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Subarray {
    int sum;
    int startI;
  };

 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int size = nums.size();

    vector<int> prefixSum(size + 1, 0);
    for (int i = 1; i <= size; i++) {
      prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    vector<vector<Subarray>> dp(4, vector<Subarray>(size + 1, {0, 0}));

    for (int count = 1; count <= 3; count++) {
      for (int endI = k * count; endI <= size; endI++) {
        int startI = endI - k;

        int curSum = prefixSum[endI] - prefixSum[startI];
        int totalSum = curSum + dp[count - 1][startI].sum;

        if (totalSum > dp[count][endI - 1].sum) {
          dp[count][endI] = {totalSum, startI};
        } else {
          dp[count][endI] = dp[count][endI - 1];
        }
      }
    }

    vector<int> answer(3, 0);
    for (int count = 3, endI = size; count >= 1; count--) {
      answer[count - 1] = dp[count][endI].startI;
      endI = answer[count - 1];
    }

    return answer;
  }
};
