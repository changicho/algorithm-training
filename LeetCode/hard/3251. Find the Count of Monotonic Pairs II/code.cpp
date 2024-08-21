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

// use dynamic programming with prefix sum
// time : O(N * M)
// space : O(M)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int countOfPairs(vector<int>& nums) {
    int size = nums.size();

    vector<int> prefixSum(1001, 0);
    for (int first = 0; first <= nums[0]; first++) {
      prefixSum[first] += (first > 0 ? prefixSum[first - 1] : 0) + 1;
      prefixSum[first] %= MOD;
    }

    for (int i = 1; i < size; i++) {
      vector<int> curPrefixSum(1001, 0);

      for (int cur = 0; cur <= nums[i]; cur++) {
        int beforeLimit = min(nums[i - 1] - nums[i] + cur, cur);
        if (beforeLimit < 0) continue;

        curPrefixSum[cur] += prefixSum[beforeLimit];
        curPrefixSum[cur] %= MOD;
      }

      for (int cur = 0; cur <= nums[i]; cur++) {
        curPrefixSum[cur] += (cur > 0 ? curPrefixSum[cur - 1] : 0);
        curPrefixSum[cur] %= MOD;
      }
      prefixSum = curPrefixSum;
    }

    int answer = prefixSum[nums.back()];
    return answer;
  }
};