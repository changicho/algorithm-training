#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & make new array

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int size = nums.size();
    vector<int> array;
    sort(nums.begin(), nums.end());

    int left = 0, right = size - 1;

    while (left < right) {
      array.emplace_back(nums[left]);
      array.emplace_back(nums[right]);

      left += 1;
      right -= 1;
    }

    if (left == right) {
      array.emplace_back(nums[left]);
    }

    nums = array;
  }
};

// use sort with swap

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 1; i < size - 1; i += 2) {
      swap(nums[i], nums[i + 1]);
    }
  }
};

// use one pass swap

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int size = nums.size();

    for (int i = 0; i < size - 1; i++) {
      bool rightSmall = (i % 2 == 0 && nums[i] > nums[i + 1]);
      bool rightBig = (i % 2 == 1 && nums[i] < nums[i + 1]);

      if (rightSmall || rightBig) {
        swap(nums[i], nums[i + 1]);
      }
    }
  }
};