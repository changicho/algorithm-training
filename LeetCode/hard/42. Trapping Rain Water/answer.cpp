#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use left-right dynamic programming

class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    int answer = 0;

    vector<int> left(size, 0), right(size, 0);

    left.front() = height.front();
    for (int i = 1; i < size; i++) {
      left[i] = max(height[i], left[i - 1]);
    }

    right.back() = height.back();
    for (int i = size - 2; i >= 0; i--) {
      right[i] = max(height[i], right[i + 1]);
    }

    for (int i = 0; i < size; i++) {
      answer += min(left[i], right[i]) - height[i];
    }

    return answer;
  }
};

// use stack

class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    int answer = 0;
    int index = 0;
    stack<int> s;

    while (index < size) {
      // 현재 높이가 stack.top 보다 작은 경우 삽입
      if (s.empty() || height[index] <= height[s.top()]) {
        s.push(index);
        index++;
        continue;
      }

      // 현재 높이가 stack.top 보다 작은 경우 stack을 비우면서 행 별로 면적 계산
      while (!s.empty() && height[index] > height[s.top()]) {
        int top = s.top();
        s.pop();
        if (s.empty()) continue;

        int line_height = (index - s.top() - 1);
        int line_width = min(height[s.top()], height[index]) - height[top];

        answer += line_width * line_height;
      }
    }

    return answer;
  }
};

// use two pointers

class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    int left = 0, right = size - 1;
    int leftMax = 0, rightMax = 0;
    int answer = 0;

    // left, right가 가장 높은 height에서 만나도록 설정
    while (left < right) {
      if (height[left] < height[right]) {
        // left++ case
        if (height[left] >= leftMax) {
          leftMax = height[left];
        } else {
          answer += (leftMax - height[left]);
        }

        left++;
      } else {
        // right-- case
        if (height[right] >= rightMax) {
          rightMax = height[right];
        } else {
          answer += (rightMax - height[right]);
        }

        right--;
      }
    }

    return answer;
  }
};