#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use two pointer & suffix maximum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    int size = nums.size();
    vector<int> suffixMaximums(size);

    for (int i = size - 1; i >= 0; i--) {
      suffixMaximums[i] =
          max(i == (size - 1) ? 0 : suffixMaximums[i + 1], nums[i]);
    }

    int answer = 0;
    for (int left = 0, right = 0; right < size; right++) {
      while (left < right && nums[left] > suffixMaximums[right]) {
        left++;
      }
      answer = max(answer, right - left);
    }

    return answer;
  }
};

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    int size = nums.size();
    stack<int> stk;

    // decreasing stack
    for (int i = 0; i < size; i++) {
      if (stk.empty() || nums[stk.top()] > nums[i]) {
        stk.push(i);
      }
    }

    int answer = 0;
    for (int i = size - 1; i >= 0; i--) {
      while (!stk.empty() && nums[stk.top()] <= nums[i]) {
        answer = max(answer, i - stk.top());

        stk.pop();
      }
    }

    return answer;
  }
};