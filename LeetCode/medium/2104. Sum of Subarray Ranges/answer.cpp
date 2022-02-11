#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use dp with brute force

class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> rangeMin(size, vector<int>(size, 0));
    vector<vector<int>> rangeMax(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
      rangeMin[i][i] = nums[i];
      rangeMax[i][i] = nums[i];
    }

    long long answer = 0;
    for (int left = 0; left < size; left++) {
      for (int right = left + 1; right < size; right++) {
        rangeMin[left][right] = min(rangeMin[left][right - 1], nums[right]);
        rangeMax[left][right] = max(rangeMax[left][right - 1], nums[right]);

        answer += rangeMax[left][right] - rangeMin[left][right];
      }
    }

    return answer;
  }
};

// use optimized dynamic programming

class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    int size = nums.size();

    long long answer = 0;
    for (int left = 0; left < size; left++) {
      int maximum = nums[left], minimum = nums[left];

      for (int right = left + 1; right < size; right++) {
        maximum = max(maximum, nums[right]);
        minimum = min(minimum, nums[right]);

        answer += maximum - minimum;
      }
    }
    return answer;
  }
};

// use monotonic stack with dynamic programming

class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    int size = nums.size();

    stack<int> minStack, maxStack;

    // minDP[i] : sum of minimum of subarrays end with i (nums[0 ~ i])
    vector<long long> minDP(size, 0);
    // maxDP[i] : sum of maximum of subarrays end with i (nums[0 ~ i])
    vector<long long> maxDP(size, 0);

    for (int i = 0; i < size; i++) {
      // pop until current index's value is bigest
      while (!minStack.empty() && nums[i] <= nums[minStack.top()]) {
        minStack.pop();
      }

      if (minStack.empty()) {
        minDP[i] = ((i + 1) * (long)nums[i]);
      } else {
        int prevMinIdx = minStack.top();
        minDP[i] = (minDP[prevMinIdx] + (i - prevMinIdx) * (long)nums[i]);
      }

      minStack.push(i);
    }

    for (int i = 0; i < size; i++) {
      // pop until current index's value is smallest
      while (!maxStack.empty() && nums[i] >= nums[maxStack.top()]) {
        maxStack.pop();
      }

      if (maxStack.empty()) {
        maxDP[i] = ((i + 1) * (long)nums[i]);
      } else {
        int prevMaxIdx = maxStack.top();
        maxDP[i] = (maxDP[prevMaxIdx] + (i - prevMaxIdx) * (long)nums[i]);
      }

      maxStack.push(i);
    }

    long long answer = 0;
    for (int i = 0; i < size; i++) {
      answer += maxDP[i];
      answer -= minDP[i];
    }

    return answer;
  }
};