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

// use binary search & sliding window
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 private:
  int convert(int bits[32]) {
    int number = 0;
    for (int bit = 0; bit < 32; bit++) {
      if (bits[bit] > 0) {
        number |= (1 << bit);
      }
    }
    return number;
  }

  bool check(vector<int>& nums, int target, int k) {
    int size = nums.size();
    int bits[32] = {0};

    for (int right = 0, left = right - k + 1; right < size; right++, left++) {
      for (int bit = 0; bit < 32; bit++) {
        if (nums[right] & (1 << bit)) {
          bits[bit]++;
        }
      }

      if (left - 1 >= 0) {
        for (int bit = 0; bit < 32; bit++) {
          if (nums[left - 1] & (1 << bit)) {
            bits[bit]--;
          }
        }
      }

      if (right >= k - 1 && convert(bits) >= target) {
        return true;
      }
    }
    return false;
  }

 public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int size = nums.size();
    int left = 1, right = size + 1;
    int answer = -1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (check(nums, k, mid)) {
        answer = mid;

        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 private:
  int convert(int bits[32]) {
    int ret = 0;
    for (int bit = 0; bit < 32; bit++) {
      if (bits[bit] > 0) {
        ret |= (1 << bit);
      }
    }
    return ret;
  }

 public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int size = nums.size();

    int answer = INT_MAX;

    int bits[32] = {0};
    for (int right = 0, left = 0; right < size; right++) {
      for (int bit = 0; bit < 32; bit++) {
        if (nums[right] & (1 << bit)) {
          bits[bit]++;
        }
      }

      while (left <= right && convert(bits) >= k) {
        answer = min(answer, right - left + 1);

        for (int bit = 0; bit < 32; bit++) {
          if (nums[left] & (1 << bit)) {
            bits[bit]--;
          }
        }
        left++;
      }
    }

    return answer == INT_MAX ? -1 : answer;
  }
};