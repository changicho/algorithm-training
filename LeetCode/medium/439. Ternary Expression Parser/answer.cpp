#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use brute force recursive with stack
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  string parseTernary(string expression) {
    int length = expression.length();
    if (length <= 1) {
      return expression;
    }
    string left = "", right = "";

    bool isTrue = false;
    if (expression.front() == 'T') isTrue = true;

    stack<bool> flags;
    flags.push(true);

    bool isLeft = true;
    for (int i = 2; i < length; i++) {
      char cur = expression[i];

      if (cur == '?') {
        flags.push(true);
      } else if (cur == ':') {
        flags.pop();

        if (flags.empty()) isLeft = false;
      }

      if (isLeft) {
        left += cur;
      } else {
        if (right.length() == 0 && cur == ':') continue;
        right += cur;
      }
    }

    if (isTrue) return parseTernary(left);
    return parseTernary(right);
  }
};

// use stack (recursive)
// time : O(N)
// space : O(N)
class Solution {
 private:
  int index = 0;

  string recursive(string &expression) {
    int length = expression.length();
    string temp = "";

    if (expression[index] == 'T' || expression[index] == 'F') {
      bool isTrue = expression[index] == 'T';
      index++;
      if (index >= length || expression[index] != '?') {
        return (isTrue ? "T" : "F");
      }

      index++;
      string left = recursive(expression);

      index++;
      string right = recursive(expression);

      return isTrue ? left : right;
    }

    for (; index < length; index++) {
      char cur = expression[index];

      if (cur == '?') {
        continue;
      } else if (cur == ':') {
        return temp;
      }
      temp += cur;
    }
    return temp;
  }

 public:
  string parseTernary(string expression) { return recursive(expression); }
};