#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int size = nums.size();
    vector<int> sorted = nums;

    sort(sorted.begin(), sorted.end());

    int left = -1, right = -1;
    for (int i = 0; i < size; i++) {
      if (nums[i] != sorted[i] && left == -1) {
        left = i;
      }
      if (nums[i] != sorted[i]) {
        right = i;
      }
    }

    if (left == -1 && right == -1) return 0;
    return right - left + 1;
  }
};

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int size = nums.size();

    vector<int> maxStack, minStack;

    int left = -1, right = -1;
    for (int i = 0; i < size; i++) {
      int reversed = size - 1 - i;

      while (!maxStack.empty() && nums[maxStack.back()] > nums[i]) {
        maxStack.pop_back();
      }
      while (!minStack.empty() && nums[minStack.back()] < nums[reversed]) {
        minStack.pop_back();
      }

      maxStack.push_back(i);
      minStack.push_back(reversed);
    }

    for (int i = 0; i < size; i++) {
      int reversed = size - 1 - i;

      if (left == -1 && i != maxStack[i]) left = i;
      if (right == -1 && reversed != minStack[i]) right = reversed;

      if (left != -1 && right != -1) break;
    }

    if (left == -1 && right == -1) return 0;
    return right - left + 1;
  }
};

// use monotonic stack one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int size = nums.size();

    stack<int> maxStack, minStack;

    int left = size, right = 0;
    for (int i = 0; i < size; i++) {
      int reversed = size - 1 - i;

      while (!maxStack.empty() && nums[maxStack.top()] > nums[i]) {
        left = min(left, maxStack.top());
        maxStack.pop();
      }
      while (!minStack.empty() && nums[minStack.top()] < nums[reversed]) {
        right = max(right, minStack.top());
        minStack.pop();
      }

      maxStack.push(i);
      minStack.push(reversed);
    }

    return right - left > 0 ? right - left + 1 : 0;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int size = nums.size();
    int left = -1, right = -1;

    int minimum = INT_MAX, maximum = INT_MIN;
    for (int i = 0; i < size; i++) {
      int reversed = size - 1 - i;

      maximum = max(maximum, nums[i]);
      minimum = min(minimum, nums[reversed]);

      if (nums[i] < maximum) right = i;
      if (nums[reversed] > minimum) left = reversed;
    }

    if (left == -1 && right == -1) return 0;
    return right - left + 1;
  }
};