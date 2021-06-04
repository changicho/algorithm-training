#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    int size = nums.size();
    vector<string> answer;
    if (size == 0) return answer;

    int left = 0, right = 0;
    for (int i = 1; i < size; i++) {
      if (nums[i] - 1 == nums[i - 1]) {
        right = i;
        continue;
      }

      if (left >= right) {
        right = left;
        answer.push_back(convert(nums[left]));
      } else {
        answer.push_back(convert(nums[left], nums[right]));
      }
      left = i;
    }

    if (left >= right) {
      answer.push_back(convert(nums[left]));
    } else {
      answer.push_back(convert(nums[left], nums[right]));
    }

    return answer;
  }

  string convert(int number) {
    return to_string(number);
  }

  string convert(int from, int to) {
    return to_string(from) + "->" + to_string(to);
  }
};

// use one pass

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> answer;
    int size = nums.size();
    if (0 == size) return answer;

    int left = 0, right = 0;
    while (left < size) {
      while (right + 1 < size && nums[right] == nums[right + 1] - 1) right++;

      if (left < right) {
        answer.push_back(convert(nums[left], nums[right]));
      } else {
        answer.push_back(convert(nums[left]));
      }

      right += 1;
      left = right;
    }

    return answer;
  }

  string convert(int number) {
    return to_string(number);
  }

  string convert(int from, int to) {
    return to_string(from) + "->" + to_string(to);
  }
};