#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use union find

class Solution {
 private:
  vector<int> parents;
  int find(int a) {
    if (parents[a] == a) return a;

    return parents[a] = find(parents[a]);
  }

  void merge(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA > parentB) swap(parentA, parentB);

    parents[parentB] = parentA;
  }

 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int>& edge : edges) {
      int a = edge[0];
      int b = edge[1];

      if (find(a) == find(b)) return false;

      merge(a, b);
    }

    unordered_set<int> groups;
    for (int i = 0; i < n; i++) {
      groups.insert(find(i));
    }

    return groups.size() == 1;
  }
};

// use DFS

class Solution {
 private:
  vector<bool> visited;
  vector<vector<int>> graph;

  bool hasCycle(int node, int parent) {
    if (visited[node]) return true;
    visited[node] = true;

    for (int next : graph[node]) {
      if (next != parent && hasCycle(next, node)) {
        return true;
      }
    }
    return false;
  }

 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    graph.resize(n);

    for (vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    visited.resize(n, false);

    if (hasCycle(0, -1)) {
      return false;
    }
    for (bool cur : visited) {
      if (!cur) return false;
    }
    return true;
  }
};