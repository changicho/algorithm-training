#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int size = nums.size();
    unordered_map<int, int> counts;

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      counts[nums[right]]++;

      while (counts[nums[right]] > k && left < right) {
        counts[nums[left]]--;
        if (counts[nums[left]] == 0) {
          counts.erase(nums[left]);
        }
        left++;
      }

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};