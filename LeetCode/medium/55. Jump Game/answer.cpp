#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int size = nums.size();

    int next = 0;
    for (int position = 0; position < nums.size() - 1; position++) {
      next = max(next, position + nums[position]);

      if (next == position) {
        return false;
      }
    }

    return true;
  }
};

// another greedy

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int size = nums.size();

    int next = size - 1;
    for (int position = size - 1; position >= 0; position--) {
      if (position + nums[position] >= next) {
        next = position;
      }
    }

    if (next == 0) {
      return true;
    }
    return false;
  }
};

// use dynamic programming (from back)

class Solution {
 public:
  bool canJump(vector<int> nums) {
    int size = nums.size();
    vector<bool> memo(size, false);

    memo[size - 1] = true;

    for (int position = size - 2; position >= 0; position--) {
      int furthest = min(position + nums[position], size - 1);

      for (int next = position + 1; next <= furthest; next++) {
        if (memo[next] == true) {
          memo[position] = true;
        }
      }
    }

    if (memo.front() == true) {
      return true;
    }
    return false;
  }
};

// use dynamic programming (from start)

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int size = nums.size();
    vector<bool> memo(size, false);
    memo[0] = true;

    for (int from = 0; from < size; from++) {
      int limit = min(size, from + nums[from] + 1);
      for (int to = from + 1; to < limit; to++) {
        if (memo[from] == true) {
          memo[to] = true;
        }
      }
    }

    if (memo.back() == true) {
      return true;
    }
    return false;
  }
};