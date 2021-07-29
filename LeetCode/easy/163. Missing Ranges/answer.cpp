#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use iteration

class Solution {
 private:
  string convert(int from, int to) {
    if (from == to) {
      return to_string(from);
    }
    return to_string(from) + "->" + to_string(to);
  }

 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    if (nums.size() == 0) {
      return {convert(lower, upper)};
    }

    vector<string> answer;
    int before = lower;
    if (lower != nums.front()) {
      answer.push_back(convert(lower, nums.front() - 1));
      before = nums.front();
    }
    for (int num : nums) {
      if (num > upper) break;

      if (before + 1 < num) {
        answer.push_back(convert(before + 1, num - 1));
      }
      before = num;
    }
    if (before + 1 <= upper) {
      answer.push_back(convert(before + 1, upper));
    }

    return answer;
  }
};

// use iteration with boundary

class Solution {
 private:
  string convert(int from, int to) {
    if (from == to) {
      return to_string(from);
    }
    return to_string(from) + "->" + to_string(to);
  }

 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> answer;

    int before = lower - 1;
    for (int i = 0; i < nums.size(); i++) {
      int cur = nums[i];
      if (before + 1 <= cur - 1) {
        answer.push_back(convert(before + 1, cur - 1));
      }
      before = cur;
    }
    if (before + 1 <= upper) {
      answer.push_back(convert(before + 1, upper));
    }

    return answer;
  }
};