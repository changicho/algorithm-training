#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> dp(size, 1);
    vector<int> prevI(size, -1);

    int maxI = 0;
    for (int cur = 1; cur < size; cur++) {
      for (int before = 0; before < cur; before++) {
        if (nums[cur] % nums[before] == 0 && dp[cur] < dp[before] + 1) {
          dp[cur] = dp[before] + 1;
          prevI[cur] = before;

          if (dp[cur] > dp[maxI]) {
            maxI = cur;
          }
        }
      }
    }

    vector<int> answer;
    while (maxI >= 0) {
      answer.push_back(nums[maxI]);
      maxI = prevI[maxI];
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};
