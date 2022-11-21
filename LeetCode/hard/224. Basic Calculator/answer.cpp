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
  int calculate(string s) {
    stack<int> nums;
    stack<int> signs;

    int answer = 0;

    int cur = 0;
    int sign = 1;
    for (char &c : s) {
      if (isdigit(c)) {
        cur *= 10;
        cur += c - '0';
      } else if (c == '+' || c == '-') {
        answer += cur * sign;
        cur = 0;

        sign = c == '+' ? +1 : -1;
      } else if (c == '(') {
        nums.push(answer);
        signs.push(sign);

        answer = 0;
        sign = 1;
      } else if (c == ')') {
        answer += cur * sign;
        cur = 0;

        answer = answer * signs.top();
        answer = answer + nums.top();

        signs.pop();
        nums.pop();
      }
    }

    answer += cur * sign;
    return answer;
  }
};