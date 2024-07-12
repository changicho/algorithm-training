#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack
// Time: O(N^2)
// space : O(N)
class Solution {
 public:
  string reverseParentheses(string s) {
    string temp = "";

    stack<string> stk;

    for (char &c : s) {
      if (c == '(') {
        stk.push(temp);
        temp = "";
      } else if (c == ')') {
        reverse(temp.begin(), temp.end());
        temp = stk.top() + temp;
        stk.pop();
      } else {
        temp += c;
      }
    }

    return temp;
  }
};

// use two pass (wormhole teleport)
// time : O(N)
// space : O(N)
class Solution {
 public:
  string reverseParentheses(string s) {
    int size = s.length();
    stack<int> stk;
    vector<int> pairs(size, -1);

    for (int from = 0; from < size; ++from) {
      if (s[from] == '(') {
        stk.push(from);
      }
      if (s[from] == ')') {
        int to = stk.top();
        stk.pop();
        pairs[from] = to;
        pairs[to] = from;
      }
    }

    string answer = "";
    for (int i = 0, dir = 1; i < size; i += dir) {
      if (s[i] == '(' || s[i] == ')') {
        i = pairs[i];
        dir *= -1;
      } else {
        answer += s[i];
      }
    }
    return answer;
  }
};