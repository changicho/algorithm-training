#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int counts[3] = {
        0,
    };
    for (int num : nums) {
      counts[num] += 1;
    }

    int index = 0;
    for (int num = 0; num <= 2; num++) {
      while (counts[num] > 0) {
        nums[index] = num;
        counts[num] -= 1;
        index++;
      }
    }
  }
};

// use one pass

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int size = nums.size();
    int zeroIdx = 0, twoIdx = size - 1;

    for (int i = 0; i <= twoIdx; ++i) {
      if (nums[i] == 0 && i != zeroIdx) {
        swap(nums[i], nums[zeroIdx]);
        i--;
        zeroIdx++;
      } else if (nums[i] == 2 && i != twoIdx) {
        swap(nums[i], nums[twoIdx]);
        i--;
        twoIdx--;
      }
    }
  }
};