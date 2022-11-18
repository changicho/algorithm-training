#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(N)
// space : O(N)
class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int answer = -1;
    for (int i = 0; i < size; i++) {
      int idx =
          lower_bound(nums.begin(), nums.end(), k - nums[i]) - nums.begin();
      idx--;

      if (idx < 0 || idx == i) continue;

      answer = max(answer, nums[i] + nums[idx]);
    }

    return answer;
  }
};

// use two pointer
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    int answer = -1;
    int left = 0, right = size - 1;
    while (left < right) {
      int sum = nums[left] + nums[right];

      if (sum < k) {
        answer = max(answer, sum);
        left++;
      } else {
        right--;
      }
    }

    return answer;
  }
};

// use two pointer with counting sort
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    int answer = -1;
    int count[1001] = {
        0,
    };

    for (int num : nums) {
      count[num]++;
    }

    int lo = 1, hi = 1000;
    while (lo <= hi) {
      if (count[hi] == 0) {
        hi--;
        continue;
      }
      if (count[lo] == 0) {
        lo++;
        continue;
      }

      if (lo + hi >= k) {
        hi--;
      } else {
        if (lo != hi || count[lo] >= 2) {
          answer = max(answer, lo + hi);
        }
        lo++;
      }
    }
    return answer;
  }
};