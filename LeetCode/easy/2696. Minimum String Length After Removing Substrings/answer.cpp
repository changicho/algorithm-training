#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minLength(string s) {
    stack<char> stk;

    for (char &c : s) {
      if (!stk.empty()) {
        if (c == 'B' && stk.top() == 'A') {
          stk.pop();
          continue;
        }
        if (c == 'D' && stk.top() == 'C') {
          stk.pop();
          continue;
        }
      }
      stk.push(c);
    }
    return stk.size();
  }
};