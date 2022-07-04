#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use disjoint set
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> parents;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
  }

 public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int> &e : edges) {
      int a = e[0], b = e[1];
      merge(a, b);
    }

    long long answer = 0;
    unordered_map<int, int> counts;
    for (int node = 0; node < n; node++) {
      counts[find(node)]++;
    }

    for (auto &it : counts) {
      int key = it.first, val = it.second;

      answer += (long long)val * (n - val);
    }
    return answer / 2;
  }
};

// use DFS
// time : O(N + E)
// space : O(N + E)
class Solution {
 private:
  vector<bool> visited;

  void recursive(int node, vector<vector<int>> &graph, int &count) {
    count++;
    visited[node] = true;
    for (int &next : graph[node]) {
      if (visited[next]) continue;
      recursive(next, graph, count);
    }
  }

 public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    visited.resize(n, false);
    vector<vector<int>> graph(n);
    for (vector<int> &e : edges) {
      int from = e[0], to = e[1];
      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    long long answer = 0;
    for (int node = 0; node < n; node++) {
      if (visited[node]) continue;

      int count = 0;
      recursive(node, graph, count);

      answer += (long long)(count) * (n - count);
    }

    return answer / 2;
  }
};