#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int countWays(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    nums.push_back(INT_MAX);

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (i + 1 > nums[i] && i + 1 < nums[i + 1]) {
        answer++;
      }
    }
    if (nums[0] != 0) answer++;
    return answer;
  }
};