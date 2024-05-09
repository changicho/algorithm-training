#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use DFS
// time : O(9999)
// space : O(9999)
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadSet(deadends.begin(), deadends.end());
    unordered_set<string> visited;

    queue<string> q;
    if (deadSet.count("0000") == 0) q.push("0000");

    int step = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        string cur = q.front();
        q.pop();

        visited.insert(cur);

        if (cur == target) return step;

        for (int i = 0; i < 4; i++) {
          string next = cur;
          next[i] = (next[i] == '9') ? '0' : next[i] + 1;
          if (visited.count(next) == 0 && deadSet.count(next) == 0) {
            visited.insert(next);
            q.push(next);
          }

          next = cur;
          next[i] = (next[i] == '0') ? '9' : next[i] - 1;
          if (visited.count(next) == 0 && deadSet.count(next) == 0) {
            visited.insert(next);
            q.push(next);
          }
        }
      }

      step++;
    }

    return -1;
  }
};