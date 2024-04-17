#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    int size = nums.size();
    long long answer = 0;

    int maximum = *max_element(nums.begin(), nums.end());

    int count = 0;

    for (int left = 0, right = 0; right < size; right++) {
      int cur = nums[right];
      if (cur == maximum) {
        count++;
      }

      while (count >= k && left <= right) {
        if (nums[left] == maximum) {
          count--;
        }
        left++;
      }

      answer += left;
    }
    return answer;
  }
};