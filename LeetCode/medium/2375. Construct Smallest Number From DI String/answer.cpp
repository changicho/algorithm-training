#include <algorithm>
#include <iostream>
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