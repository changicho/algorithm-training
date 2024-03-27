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
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) return 0;

    int size = nums.size();

    int product = 1;
    int answer = 0;
    int left = 0;

    for (int right = 0; right < size; ++right) {
      product *= nums[right];
      while (product >= k) {
        product /= nums[left];
        ++left;
      }
      answer += max(0, right - left + 1);
    }

    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int size = nums.size();

    int answer = 0;
    long long multiple = 1;
    for (int left = 0, right = 0; right < size; right++) {
      multiple *= nums[right];
      while (multiple >= k && left <= right) {
        multiple /= nums[left];
        left++;
      }

      answer += right - left + 1;
    }

    return answer;
  }
};