#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// DFS with backtracking

class Solution {
 public:
  vector<string> ret;
  int size;
  vector<string> generateParenthesis(int n) {
    size = n;

    recursive(0, 0, "");

    return ret;
  }

  void recursive(int open, int close, string cur) {
    if (close == size && open == size) {
      ret.push_back(cur);
    }
    if (open < size) {
      recursive(open + 1, close, cur + "(");
    }
    if (close < open) {
      recursive(open, close + 1, cur + ")");
    }
  }
};

// divide and conquer

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;

    if (n == 0) {
      ret.push_back("");
    } else {
      for (int leftSize = 0; leftSize < n; leftSize++) {
        for (string leftPart : generateParenthesis(leftSize)) {
          for (string rightPart : generateParenthesis(n - 1 - leftSize)) {
            ret.push_back("(" + leftPart + ")" + rightPart);
          }
        }
      }
    }
    return ret;
  }
};