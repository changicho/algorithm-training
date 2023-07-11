#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int alternatingSubarray(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;
    for (int left = 0; left < size - 1; left++) {
      int diff = abs(nums[left + 1] - nums[left]);

      if (abs(diff) != 1) continue;
      for (int right = left + 1; right < size; right++) {
        int curDiff = nums[right] - nums[right - 1];

        if (curDiff != diff) break;
        if (right - left + 1 >= 2) {
          answer = max(answer, right - left + 1);
        }
        diff *= -1;
      }
    }

    if (answer == 0) return -1;

    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int alternatingSubarray(vector<int>& nums) {
    int size = nums.size();

    int left = 1, right = 0;

    int diff = INT_MAX;
    int answer = 0;
    for (int right = 1, left = 0; right < size; right++) {
      int curDiff = nums[right] - nums[right - 1];

      if (curDiff == -diff) {
        diff *= -1;
        answer = max(answer, right - left + 1);
        continue;
      }

      if (curDiff == 1) {
        diff = curDiff;
        left = right - 1;
        answer = max(answer, right - left + 1);
      } else {
        diff = INT_MAX;
      }
    }

    if (answer == 0) return -1;
    return answer;
  }
};