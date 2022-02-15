#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use monotonic stack

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();

    vector<int> answer(size, -1);
    stack<int> maxStack;  // idx, decrease

    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      // pop stack's top until top's val is same or bigger than current
      while (!maxStack.empty() && cur > nums[maxStack.top()]) {
        answer[maxStack.top()] = cur;
        maxStack.pop();
      }

      maxStack.push(i);
    }

    // loop one more time for circular case
    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      while (!maxStack.empty() && cur > nums[maxStack.top()]) {
        answer[maxStack.top()] = cur;
        maxStack.pop();
      }
    }

    return answer;
  }
};

// use optimized bruteforce

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer(size, -1);

    for (int i = 0; i < size; i++) {
      for (int move = 1; move < size; move++) {
        if (nums[(i + move) % size] <= nums[i]) continue;

        answer[i] = nums[(i + move) % size];
        break;
      }
    }

    return answer;
  }
};