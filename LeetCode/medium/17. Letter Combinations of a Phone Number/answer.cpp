#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(4^N * N)
// space : O(4^N * N)
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    string letters[10] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;

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
      int digit = digits[index] - '0';
      for (char &c : letters[digit]) {
        q.push(cur + c);
      }
    }

    return ret;
  }
};

// use DFS
// time : O(4^N * N)
// space : O(N)
class Solution {
 private:
  string letters[10] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> answer;

  void recursive(int index, string &digits, string &cur) {
    if (index == digits.length()) {
      if (cur != "") {
        answer.push_back(cur);
      }
      return;
    }

    int targetIndex = digits[index] - '0';
    for (char c : letters[targetIndex]) {
      cur.push_back(c);
      recursive(index + 1, digits, cur);
      cur.pop_back();
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    string cur = "";
    recursive(0, digits, cur);

    return answer;
  }
};