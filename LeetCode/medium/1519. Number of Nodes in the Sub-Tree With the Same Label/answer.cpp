#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> counts;
  vector<vector<int>> graph;
  vector<bool> visited;
  string labels;

  vector<int> recursive(int node) {
    visited[node] = true;

    vector<int> ret(26, 0);
    ret[labels[node] - 'a']++;

    for (int &next : graph[node]) {
      if (visited[next]) continue;
      vector<int> child = recursive(next);

      for (int i = 0; i < 26; i++) {
        ret[i] += child[i];
      }
    }

    counts[node] = ret[labels[node] - 'a'];
    return ret;
  }

 public:
  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    counts.resize(n, 0);
    graph.resize(n);
    visited.resize(n, 0);
    this->labels = labels;

    for (vector<int> &e : edges) {
      int from = e.front(), to = e.back();

      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    recursive(0);

    return counts;
  }
};