#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * (log_2(10^9)))
// space : O(N)
class Solution {
 private:
  bool calc(vector<long> nums, long long target) {
    int size = nums.size();
    for (int i = size - 1; i > 0; i--) {
      if (nums[i] > target) {
        long diff = nums[i] - target;
        nums[i] -= diff;
        nums[i - 1] += diff;
      }
    }
    if (nums[0] > target) return false;
    return true;
  }

 public:
  int minimizeArrayValue(vector<int>& nums) {
    int left = 0, right = 1e9 + 1;

    vector<long> arr(nums.begin(), nums.end());
    int answer = right;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (calc(arr, mid)) {
        // pick left
        right = mid;
        answer = min(answer, mid);
      } else {
        // pick right
        left = mid + 1;
      }
    }
    return answer;
  }
};

// use prefix sum
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    long long answer = 0;

    long long prefixSum = 0;
    // Iterate over nums, update prefix sum and answer.
    for (int i = 0; i < nums.size(); i++) {
      prefixSum += nums[i];
      answer = max(answer, (prefixSum + i) / (i + 1));
    }

    return answer;
  }
};