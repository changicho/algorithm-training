#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    char table[128];
    table['('] = ')';
    table['['] = ']';
    table['{'] = '}';

    bool answer = true;
    stack<char> bracket;

    for (char c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{': {
          bracket.push(c);
          break;
        }
        case ')':
        case ']':
        case '}': {
          if (bracket.empty() || table[bracket.top()] != c) {
            answer = false;
            break;
          }
          bracket.pop();
          break;
        }
      }
    }

    if (!bracket.empty()) {
      answer = false;
    }

    return answer;
  }
};