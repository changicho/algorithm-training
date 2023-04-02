#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use bit count
// time : O(N)
// space : O(2^20)
class Solution {
 public:
  long long beautifulSubarrays(vector<int>& nums) {
    // bit count and can make answer if all bit count is even

    long long answer = 0;
    int dp[1 << 20] = {
        0,
    };

    int bitMask = 0;
    int allPass = 0;

    for (int num : nums) {
      for (int i = 0; i < 20; i++) {
        int bit = (1 << i);

        if ((num & bit) > 0) {
          // toggle bit on bitMask
          if ((bitMask & bit) > 0) {
            bitMask -= bit;
          } else {
            bitMask += bit;
          }
        }
      }

      if (bitMask == allPass) answer++;

      answer += dp[bitMask];
      dp[bitMask]++;
    }
    return answer;
  }
};