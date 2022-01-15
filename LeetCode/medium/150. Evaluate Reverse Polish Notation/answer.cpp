#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 private:
  string operation(string &first, string &second, string &oper) {
    if (oper == "+") {
      return to_string(stoi(second) + stoi(first));
    }
    if (oper == "-") {
      return to_string(stoi(second) - stoi(first));
    }
    if (oper == "/") {
      return to_string(stoi(second) / stoi(first));
    }
    if (oper == "*") {
      return to_string(stoi(second) * stoi(first));
    }
    return "0";
  }

 public:
  int evalRPN(vector<string> &tokens) {
    stack<string> nums;

    for (string &t : tokens) {
      if (t == "+" || t == "-" || t == "/" || t == "*") {
        string first = nums.top();
        nums.pop();
        string second = nums.top();
        nums.pop();

        string result = operation(first, second, t);
        nums.push(result);
      } else {
        nums.push(t);
      }
    }

    return stoi(nums.top());
  }
};