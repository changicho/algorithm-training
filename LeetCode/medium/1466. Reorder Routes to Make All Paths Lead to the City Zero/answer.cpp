#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// use reverse BFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Edge {
    int from, to, cost;
  };

 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<Edge>> graph(n);
    for (vector<int>& c : connections) {
      int from = c[0], to = c[1];

      graph[from].push_back({from, to, 1});
      graph[to].push_back({to, from, 0});
    }

    queue<Edge> q;
    vector<bool> visited(n, false);
    q.push({0, 0, 0});
    int answer = 0;
    while (!q.empty()) {
      Edge cur = q.front();
      q.pop();

      if (visited[cur.to]) continue;
      visited[cur.to] = true;
      answer += cur.cost;

      for (Edge next : graph[cur.to]) {
        q.push(next);
      }
    }
    return answer;
  }
};