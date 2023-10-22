#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use topological sort
// time : O(V + E)
// space : O(V + E)
class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> graph(n);
    vector<int> inDegrees = vector(n, 0);

    for (vector<int>& edge : relations) {
      int x = edge[0] - 1;
      int y = edge[1] - 1;
      graph[x].push_back(y);
      inDegrees[y]++;
    }

    queue<int> q;
    vector<int> maxTime = vector(n, 0);

    for (int node = 0; node < n; node++) {
      if (inDegrees[node] == 0) {
        q.push(node);
        maxTime[node] = time[node];
      }
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int& next : graph[node]) {
        maxTime[next] = max(maxTime[next], maxTime[node] + time[next]);
        inDegrees[next]--;

        if (inDegrees[next] == 0) {
          q.push(next);
        }
      }
    }

    int answer = 0;
    for (int node = 0; node < n; node++) {
      answer = max(answer, maxTime[node]);
    }

    return answer;
  }
};