#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  bool isMutation(string &a, string &b) {
    int diffCount = 0;
    for (int i = 0; i < 8; i++) {
      if (a[i] != b[i]) diffCount++;
    }
    return diffCount == 1;
  }

 public:
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    queue<string> q;
    unordered_set<string> visited;
    q.push(startGene);
    int step = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        string cur = q.front();
        q.pop();

        if (visited.count(cur) > 0) continue;
        visited.insert(cur);

        if (cur == endGene) {
          return step;
        }

        for (string &next : bank) {
          if (!isMutation(cur, next)) continue;

          q.push(next);
        }
      }

      step++;
    }

    return -1;
  }
};