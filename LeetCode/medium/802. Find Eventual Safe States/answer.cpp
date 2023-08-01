#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use topological sort
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int size = graph.size();
    vector<int> inDegrees(size);
    vector<vector<int>> reverseGraph(size);

    for (int node = 0; node < size; node++) {
      for (int& next : graph[node]) {
        reverseGraph[next].push_back(node);
        inDegrees[node]++;
      }
    }

    queue<int> q;
    for (int node = 0; node < size; node++) {
      if (inDegrees[node] == 0) {
        q.push(node);
      }
    }

    vector<bool> isSafe(size);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      isSafe[node] = true;

      for (int& next : reverseGraph[node]) {
        inDegrees[next]--;
        if (inDegrees[next] == 0) {
          q.push(next);
        }
      }
    }

    vector<int> safeNodes;
    for (int node = 0; node < size; node++) {
      if (isSafe[node]) {
        safeNodes.push_back(node);
      }
    }
    return safeNodes;
  }
};

// use DFS
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<vector<int>> reverseGraph;
  vector<bool> visited;
  vector<bool> inStack;

  bool hasCycle(int node) {
    if (inStack[node]) return true;
    if (visited[node]) return false;

    visited[node] = true;
    inStack[node] = true;
    for (auto neighbor : reverseGraph[node]) {
      if (hasCycle(neighbor)) {
        return true;
      }
    }

    inStack[node] = false;
    return false;
  }

 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int size = graph.size();
    this->reverseGraph.resize(size);
    this->visited.resize(size, false);
    this->inStack.resize(size, false);

    for (int node = 0; node < size; node++) {
      for (int& next : graph[node]) {
        reverseGraph[node].push_back(next);
      }
    }

    for (int node = 0; node < size; node++) {
      hasCycle(node);
    }

    vector<int> safeNodes;
    for (int node = 0; node < size; node++) {
      if (!inStack[node]) {
        safeNodes.push_back(node);
      }
    }
    return safeNodes;
  }
};