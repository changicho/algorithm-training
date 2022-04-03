#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use topological sort
// time : O(V^2 * log_2(V) + E)
// space : O(V + E)
class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n, 0);
    // O(E)
    for (vector<int> &e : edges) {
      graph[e[0]].push_back(e[1]);
      inDegrees[e[1]]++;
    }

    queue<int> q;
    // O(V)
    for (int node = 0; node < n; node++) {
      if (inDegrees[node] == 0) q.push(node);
    }

    vector<set<int>> ancestorSets(n);
    // O(V)
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      // total O(E)
      for (int &next : graph[cur]) {
        // add cur and visited node of cur
        ancestorSets[next].insert(cur);
        // O(V)
        for (int node : ancestorSets[cur]) {
          ancestorSets[next].insert(node);
        }

        inDegrees[next]--;
        if (inDegrees[next] == 0) {
          q.push(next);
        }
      }
    }

    vector<vector<int>> ancestors(n);
    // O(V)
    for (int node = 0; node < n; node++) {
      // O(V)
      for (int a : ancestorSets[node]) {
        ancestors[node].push_back(a);
      }
    }
    return ancestors;
  }
};

// use DFS
// time : O(V * (V + E))
// space : O(V + E)
class Solution {
 private:
  // O(V + E)
  void dfs(vector<vector<int>> &graph, int start, int cur,
           vector<vector<int>> &ancestors, vector<bool> &visited) {
    visited[cur] = true;

    // total O(E)
    for (int &next : graph[cur]) {
      if (visited[next]) continue;

      ancestors[next].push_back(start);
      dfs(graph, start, next, ancestors, visited);
    }
  }

 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> ancestors(n), graph(n);

    // O(E)
    for (vector<int> &e : edges) {
      graph[e[0]].push_back(e[1]);
    }

    // O(V)
    for (int node = 0; node < n; node++) {
      vector<bool> visited(n);

      dfs(graph, node, node, ancestors, visited);
    }
    return ancestors;
  }
};