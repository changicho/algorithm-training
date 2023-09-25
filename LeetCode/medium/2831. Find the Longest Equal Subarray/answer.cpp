#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int longestEqualSubarray(vector<int>& nums, int k) {
    int size = nums.size();

    unordered_map<int, int> counts;

    int maxFreq = 0;
    for (int left = 0, right = 0; right < size; right++) {
      counts[nums[right]]++;
      maxFreq = max(maxFreq, counts[nums[right]]);

      if (right - left + 1 - maxFreq > k) {
        counts[nums[left]]--;
        left++;
      }
    }

    return maxFreq;
  }
};