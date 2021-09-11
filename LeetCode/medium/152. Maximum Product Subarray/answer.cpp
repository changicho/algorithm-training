#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int maxProduct(vector<int> &nums) {
    int size = nums.size();
    int answer = nums.front();
    int left = 0, right = 0;

    for (int i = 0; i < size; i++) {
      left = (left == 0 ? 1 : left) * nums[i];
      right = (right == 0 ? 1 : right) * nums[size - 1 - i];

      answer = max(answer, max(left, right));
    }
    return answer;
  }
};

// use dynamic programming one pass

class Solution {
 public:
  int maxProduct(vector<int> &nums) {
    int size = nums.size();
    int answer = nums.front();
    int temp = 0;

    for (int i = 0; i < size; i++) {
      if (temp == 0) temp = 1;
      temp = temp * nums[i];

      answer = max(answer, temp);
    }

    temp = 0;
    for (int i = size - 1; i >= 0; i--) {
      if (temp == 0) temp = 1;
      temp = temp * nums[i];

      answer = max(answer, temp);
    }

    return answer;
  }
};