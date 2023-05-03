#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack & simulation
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int size = pushed.size();

    stack<int> stk;
    int idx = 0;
    for (int& pop : popped) {
      while (idx < size && (stk.empty() || stk.top() != pop)) {
        stk.push(pushed[idx]);
        idx++;
      }

      if (pop == stk.top()) {
        stk.pop();
      }
    }

    return stk.empty();
  }
};