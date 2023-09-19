#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use topological sort
// time : O(V + E)
// space : O(V + E)
class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>> &relations) {
    vector<vector<int>> graph(n);

    vector<int> inDegrees(n, 0);

    for (auto &r : relations) {
      int from = r[0] - 1, to = r[1] - 1;
      graph[from].push_back(to);
      inDegrees[to]++;
    }

    queue<int> q;
    vector<bool> visited(n);
    int visitedCount = 0;
    for (int i = 0; i < n; i++) {
      if (inDegrees[i] == 0) q.push(i);
    }
    int answer = 0;

    while (!q.empty()) {
      int size = q.size();
      answer++;
      while (size--) {
        int cur = q.front();
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = true;
        visitedCount++;

        for (int &next : graph[cur]) {
          inDegrees[next]--;

          if (inDegrees[next] == 0) q.push(next);
        }
      }
    }

    if (visitedCount < n) return -1;
    return answer;
  }
};