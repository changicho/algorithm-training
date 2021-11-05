#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS

class Solution {
  void recursive(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    for (int next : graph[node]) {
      if (visited[next]) continue;

      recursive(next, graph, visited);
    }
  }

 public:
  bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    vector<bool> visited(n, false);

    vector<vector<int>> graph(n);

    for (vector<int> &edge : edges) {
      int from = edge[0], to = edge[1];

      graph[from].emplace_back(to);
      graph[to].emplace_back(from);
    }

    recursive(start, graph, visited);

    return visited[end];
  }
};

// use union find

class Solution {
  vector<int> parents;
  vector<int> counts;

  int find(int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    int parentA = find(a), parentB = find(b);
    if (parentA == parentB) return;

    if (parentA > parentB) swap(parentA, parentB);
    if (counts[parentA] < parents[parentB]) swap(parentA, parentB);

    parents[parentB] = parentA;
    counts[parentA] += counts[parentB];
    counts[parentB] = 0;
  }

 public:
  bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    parents.resize(n);
    counts.resize(n, 1);

    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int> &edge : edges) {
      int a = edge[0], b = edge[1];

      merge(a, b);
    }

    return find(start) == find(end);
  }
};