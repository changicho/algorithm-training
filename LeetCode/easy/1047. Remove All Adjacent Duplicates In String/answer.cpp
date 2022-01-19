#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  string removeDuplicates(string s) {
    stack<char> stk;

    // iterate char in s
    for (char &c : s) {
      // if c is same with before
      if (!stk.empty() && stk.top() == c) {
        stk.pop();
        continue;
      }
      stk.push(c);
    }

    // append char in stack
    string answer = "";
    while (!stk.empty()) {
      answer += stk.top();
      stk.pop();
    }

    // reverse answer
    reverse(answer.begin(), answer.end());
    return answer;
  }
};