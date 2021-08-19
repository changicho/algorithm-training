#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use make new vector

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    vector<int> temp;

    int count = 0;
    for (int num : nums) {
      if (num == 0) {
        count += 1;
      } else {
        temp.emplace_back(num);
      }
    }

    for (int i = 0; i < count; i++) {
      temp.emplace_back(0);
    }

    nums = temp;
  }
};

// use index moving

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int index = 0;

    for (int num : nums) {
      if (num != 0) {
        nums[index] = num;
        index++;
      }
    }

    for (int i = index; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};

// use swap

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int index = 0;
    for (int& num : nums) {
      if (num != 0) {
        swap(nums[index], num);
        index++;
      }
    }
  }
};