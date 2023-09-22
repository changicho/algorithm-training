#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  int validSubarrays(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;

    stack<int> stk;
    for (int i = 0; i < size; i++) {
      // pop
      while (!stk.empty() && nums[i] < nums[stk.top()]) {
        answer += (i - stk.top());
        stk.pop();
      }

      stk.push(i);
    }

    while (!stk.empty()) {
      answer += (nums.size() - stk.top());
      stk.pop();
    }

    return answer;
  }
};