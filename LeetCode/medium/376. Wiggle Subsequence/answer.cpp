#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return size;

    vector<int> up(size), down(size);
    // initialize
    up[0] = down[0] = 1;
    int answer = 1;

    for (int i = 1; i < size; ++i) {
      for (int before = 0; before < i; ++before) {
        if (nums[i] > nums[before]) {
          up[i] = max(up[i], down[before] + 1);
        } else if (nums[i] < nums[before]) {
          down[i] = max(down[i], up[before] + 1);
        }
      }
    }

    answer = max(answer, max(up.back(), down.back()));
    return answer;
  }
};

// use dynamic programming (one pass)

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return size;

    vector<int> up(size), down(size);
    up[0] = down[0] = 1;

    for (int i = 1; i < size; ++i) {
      up[i] = nums[i] > nums[i - 1] ? down[i - 1] + 1 : up[i - 1];
      down[i] = nums[i] < nums[i - 1] ? up[i - 1] + 1 : down[i - 1];
    }

    return max(up.back(), down.back());
  }
};

// use dynamic programming (space optimized)

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return size;

    int down = 1, up = 1;

    for (int i = 1; i < size; ++i) {
      if (nums[i] > nums[i - 1]) {
        up = down + 1;
      } else if (nums[i] < nums[i - 1]) {
        down = up + 1;
      }
    }

    return max(up, down);
  }
};

// use greedy algorithm

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return size;

    int prevdiff = nums[1] - nums[0];
    int count = prevdiff != 0 ? 1 : 0;
    for (int i = 2; i < size; ++i) {
      int diff = nums[i] - nums[i - 1];
      if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
        count++;
        prevdiff = diff;
      }
    }
    return 1 + count;
  }
};