#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS with node & edge count
// time : O(V + E)
// space : O(V + E)
class Solution {
 private:
  bool visited[51] = {
      false,
  };

  vector<vector<int>> graph;
  int answer = 0;

  void recursive(int node, int &nodeCount, int &edgeCount) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;

    nodeCount++;
    edgeCount += graph[node].size();

    for (int &next : graph[node]) {
      recursive(next, nodeCount, edgeCount);
    }
  }

 public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    graph.resize(n);

    for (vector<int> &e : edges) {
      int from = e[0], to = e[1];

      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    int answer = 0;
    for (int node = 0; node < n; node++) {
      if (visited[node]) continue;

      int nodeCount = 0, edgeCount = 0;
      recursive(node, nodeCount, edgeCount);
      if (nodeCount * (nodeCount - 1) == edgeCount) {
        answer++;
      }
    }
    return answer;
  }
};