#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use color DFS

class Solution {
 private:
  vector<vector<int>> graph;
  vector<int> visited;  // key:node, value:color
  bool answer = true;

  void recursive(int node, int color) {
    if (node > graph.size()) return;
    if (visited[node] != 0) {
      if (visited[node] == color) return;
      answer = false;
      return;
    }

    visited[node] = color;
    for (int next : graph[node]) {
      recursive(next, color * -1);
    }
  }

 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    graph.resize(n + 1);
    visited.resize(n + 1);

    for (vector<int>& edge : dislikes) {
      int a = edge[0], b = edge[1];
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
      if (visited[i] == 0) {
        recursive(i, 1);
      }
    }

    return answer;
  }
};