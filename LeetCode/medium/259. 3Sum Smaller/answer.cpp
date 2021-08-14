#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int size = nums.size();
    if (size < 3) return 0;

    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int i = 0; i < size - 2; i++) {
      int cur = nums[i];

      int left = i + 1, right = size - 1;

      while (left < right) {
        int curSum = cur + nums[left] + nums[right];
        if (curSum < target) {
          answer += right - left;
          left += 1;
        } else {
          right -= 1;
        }
      }
    }

    return answer;
  }
};

// use lower bound

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int size = nums.size();
    if (size < 3) return 0;

    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int i = 0; i < size - 2; i++) {
      for (int j = i + 1; j < size - 1; j++) {
        int k = lower_bound(nums.begin() + j + 1, nums.end(), target - nums[i] - nums[j]) - nums.begin();
        answer += k - (j + 1);
      }
    }

    return answer;
  }
};

// use binary search

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int size = nums.size();
    if (size < 3) return 0;

    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int i = 0; i < size - 2; i++) {
      for (int j = i + 1; j < size - 1; j++) {
        int left = j + 1, right = size;
        while (left < right) {
          int mid = (left + right) / 2;
          if (nums[mid] + nums[i] + nums[j] < target) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }

        answer += right - (j + 1);
      }
    }

    return answer;
  }
};