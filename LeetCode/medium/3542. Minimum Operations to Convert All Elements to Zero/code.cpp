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
  int minOperations(vector<int>& nums) {
    int answer = 0;

    stack<int> stk;
    for (int& num : nums) {
      while (!stk.empty() && stk.top() > num) {
        stk.pop();
      }

      if (num > 0 && (stk.empty() || stk.top() < num)) {
        stk.push(num);
        answer++;
      }
    }

    return answer;
  }
};