#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy algorithm
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long minimumReplacement(vector<int>& nums) {
    int size = nums.size();

    long long answer = 0;
    for (int i = size - 2; i >= 0; i--) {
      if (nums[i] <= nums[i + 1]) {
        continue;
      }

      long long replaceCount =
          ceil((nums[i] + nums[i + 1] - 1LL) / (nums[i + 1]));

      answer += replaceCount - 1;

      nums[i] = nums[i] / replaceCount;
    }

    return answer;
  }
};