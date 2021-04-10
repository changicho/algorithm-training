#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;

    vector<string> combi;
    for (char digit : digits) {
      combi.push_back(letters[digit - '0']);
    }

    queue<string> q;
    q.push("");

    while (!q.empty()) {
      string cur = q.front();
      q.pop();

      if (cur.length() == digits.length()) {
        if (cur != "") {
          ret.push_back(cur);
        }
        continue;
      }

      int index = cur.length();
      for (char c : combi[index]) {
        q.push(cur + c);
      }
    }

    return ret;
  }
};

// use DFS

class Solution {
 public:
  string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> answer;
  vector<string> letterCombinations(string digits) {
    recursive(0, digits, "");

    return answer;
  }

  void recursive(int index, string digits, string cur) {
    if (index == digits.length()) {
      if (cur != "") {
        answer.push_back(cur);
      }
      return;
    }

    int targetIndex = digits[index] - '0';
    for (char c : letters[targetIndex]) {
      recursive(index + 1, digits, cur + c);
    }
  }
};