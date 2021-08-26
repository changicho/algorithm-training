#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> array;
    for (int& num : nums) {
      array.emplace_back(num * num);
    }

    sort(array.begin(), array.end());
    return array;
  }
};

// use two pointer with dq

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    deque<int> dq;

    int left = 0, right = nums.size() - 1;

    while (left < right) {
      if (abs(nums[left]) > abs(nums[right])) {
        dq.push_front(nums[left] * nums[left]);
        left += 1;
      } else {
        dq.push_front(nums[right] * nums[right]);
        right -= 1;
      }
    }

    dq.push_front(nums[left] * nums[left]);

    vector<int> array;
    for (int num : dq) {
      array.emplace_back(num);
    }
    return array;
  }
};
