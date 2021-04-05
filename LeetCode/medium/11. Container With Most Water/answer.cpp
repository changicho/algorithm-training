#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int answer = 0;

    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
      int curAnswer = (right - left) * min(height[left], height[right]);
      answer = max(curAnswer, answer);

      if (height[left] <= height[right]) {
        left += 1;
      } else {
        right -= 1;
      }
    }

    return answer;
  }
};