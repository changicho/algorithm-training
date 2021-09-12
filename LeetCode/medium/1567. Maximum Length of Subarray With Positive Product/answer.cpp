#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (prefix suffix)

class Solution {
 public:
  int getMaxLen(vector<int> &nums) {
    int size = nums.size();

    int answer = 0;
    int temp = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
      if (temp == 0) {
        count = 0;
        temp = 1;
      }
      temp = temp * (nums[i] == 0 ? 0 : (nums[i] > 0 ? 1 : -1));
      count += 1;

      if (0 < temp) {
        answer = max(answer, count);
      }
    }

    temp = 0;
    count = 0;
    for (int i = size - 1; i >= 0; i--) {
      if (temp == 0) {
        count = 0;
        temp = 1;
      }
      temp = temp * (nums[i] == 0 ? 0 : (nums[i] > 0 ? 1 : -1));
      count += 1;

      if (0 < temp) {
        answer = max(answer, count);
      }
    }

    return answer;
  }
};

// use dynamic programming (one pass)

class Solution {
 public:
  int getMaxLen(vector<int> &nums) {
    int size = nums.size();

    int answer = 0;
    int left = 0, right = 0;
    int leftCount = 0, rightCount = 0;

    for (int i = 0; i < size; i++) {
      int leftIdx = i, rightIdx = size - 1 - i;

      // left part
      if (left == 0) {
        leftCount = 0;
        left = 1;
      }
      left = left * (nums[leftIdx] == 0 ? 0 : (nums[leftIdx] > 0 ? 1 : -1));
      leftCount += 1;
      if (0 < left) answer = max(answer, leftCount);

      // right part
      if (right == 0) {
        rightCount = 0;
        right = 1;
      }
      right = right * (nums[rightIdx] == 0 ? 0 : (nums[rightIdx] > 0 ? 1 : -1));
      rightCount += 1;
      if (0 < right) answer = max(answer, rightCount);
    }

    return answer;
  }
};

// use one pass

class Solution {
 public:
  int getMaxLen(vector<int> &nums) {
    int size = nums.size();
    int firstNegative = -1, zeroPosition = -1;
    int countNegative = 0, answer = 0;

    for (int i = 0; i < size; i++) {
      if (nums[i] < 0) {
        countNegative++;

        if (firstNegative == -1) firstNegative = i;
      }

      if (nums[i] == 0) {
        countNegative = 0;
        firstNegative = -1;
        zeroPosition = i;
        continue;
      }

      if (countNegative % 2 == 0) {
        answer = max(i - zeroPosition, answer);
      } else {
        answer = max(i - firstNegative, answer);
      }
    }

    return answer;
  }
};