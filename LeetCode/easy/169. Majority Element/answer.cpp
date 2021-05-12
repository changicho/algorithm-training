#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort with upper_bound

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int answer = nums.front();
    int size = nums.size();
    int count = 0;
    sort(nums.begin(), nums.end());

    auto begin = nums.begin();
    count = upper_bound(nums.begin(), nums.end(), *begin) - lower_bound(nums.begin(), nums.end(), *begin);

    while (begin != nums.end()) {
      auto nextBegin = upper_bound(nums.begin(), nums.end(), *begin);
      int cur_count = nextBegin - lower_bound(nums.begin(), nums.end(), *begin);
      if (cur_count > (size / 2)) {
        answer = *begin;
        break;
      }
      begin = nextBegin;
    }

    return answer;
  }
};

// use sort

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    return nums[size / 2];
  }
};

// use Boyer-Moore voting algorithm

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate;

    for (int num : nums) {
      if (count == 0) {
        candidate = num;
      }
      count += (num == candidate) ? 1 : -1;
    }

    return candidate;
  }
};