#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use DFS (backtracking)
// time : O(9^N)
// space : O(N)
class Solution {
 private:
  string answer = "987654321";

  void recursive(int index, string &pattern, string &cur,
                 vector<bool> &visited) {
    if (index == pattern.length()) {
      answer = min(answer, cur);
      return;
    }

    if (pattern[index] == 'D') {
      for (int num = (cur.back() - '0') - 1; num >= 1; num--) {
        if (visited[num]) continue;

        cur.push_back(char(num + '0'));
        visited[num] = true;
        recursive(index + 1, pattern, cur, visited);
        visited[num] = false;
        cur.pop_back();
      }
    } else {
      for (int num = (cur.back() - '0') + 1; num <= 9; num++) {
        if (visited[num]) continue;

        cur.push_back(char(num + '0'));
        visited[num] = true;
        recursive(index + 1, pattern, cur, visited);
        visited[num] = false;
        cur.pop_back();
      }
    }
  }

 public:
  string smallestNumber(string pattern) {
    vector<bool> visited(10, false);

    for (int num = 1; num <= 9; num++) {
      string cur = {
          char(num + '0'),
      };

      visited[num] = true;
      recursive(0, pattern, cur, visited);
      visited[num] = false;
    }

    return answer;
  }
};

// use greedy
// time : O(N)
// space : O(N)
class Solution {
 public:
  string smallestNumber(string s) {
    int size = s.size();

    string answer;
    for (int num = 0, index = 0; num <= size; num++) {
      answer.push_back('1' + num);

      if (num == size || s[num] == 'I') {
        reverse(answer.begin() + index, answer.end());
        index = num + 1;
      }
    }
    return answer;
  }
};

// use stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  string smallestNumber(string pattern) {
    int size = pattern.size();
    string result;
    stack<int> stk;

    for (int i = 0; i <= size; i++) {
      stk.push(i + 1);

      if (i == pattern.size() || pattern[i] == 'I') {
        while (!stk.empty()) {
          result.push_back(stk.top() + '0');
          stk.pop();
        }
      }
    }

    return result;
  }
};