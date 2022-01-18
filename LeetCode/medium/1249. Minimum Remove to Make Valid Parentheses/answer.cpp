#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    int length = s.length();

    stack<int> stk;

    // find valid
    for (int i = 0; i < length; i++) {
      char &c = s[i];
      if (c == '(') {
        stk.push(i);
        continue;
      } else if (c == ')') {
        if (stk.empty()) {
          s[i] = '-';
          continue;
        }

        stk.pop();
        continue;
      }
      continue;
    }

    // check to remove
    while (!stk.empty()) {
      s[stk.top()] = '-';
      stk.pop();
    }

    // convert
    string answer = "";
    for (char &c : s) {
      if (c == '-') continue;
      answer += c;
    }

    return answer;
  }
};