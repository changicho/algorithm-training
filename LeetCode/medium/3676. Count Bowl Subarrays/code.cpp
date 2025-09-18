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

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long bowlSubarrays(vector<int>& nums) {
    int size = nums.size();

    stack<int> stk;
    long long answer = 0;

    for (int i = 0; i < size; i++) {
      while (!stk.empty() && nums[stk.top()] <= nums[i]) {
        if (i - stk.top() + 1 >= 3) answer++;
        stk.pop();
      }

      if (!stk.empty() && i - stk.top() + 1 >= 3) {
        answer++;
      }

      stk.push(i);
    }

    return answer;
  }
};