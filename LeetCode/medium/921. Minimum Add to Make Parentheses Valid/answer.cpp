#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  int minAddToMakeValid(string s) {
    stack<char> stk;

    int answer = 0;
    for (char &c : s) {
      if (c == '(') {
        stk.push(c);
        continue;
      }

      if (stk.empty()) {
        answer += 1;
        continue;
      }

      stk.pop();
    }

    answer += stk.size();

    return answer;
  }
};

// use counter

class Solution {
 public:
  int minAddToMakeValid(string s) {
    int counter = 0;

    int answer = 0;
    for (char &c : s) {
      if (c == '(') {
        counter++;
        continue;
      }

      if (counter == 0) {
        answer += 1;
        continue;
      }

      counter--;
    }

    answer += counter;

    return answer;
  }
};