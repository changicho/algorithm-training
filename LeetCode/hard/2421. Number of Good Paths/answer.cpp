#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use union find
// time : O(N * log_2(N) + E)
// space : O(N + E)
class Solution {
 private:
  vector<vector<int>> graph;
  vector<int> parents;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);

    if (a > b) swap(a, b);
    if (a == b) return;
    parents[b] = a;
  }

 public:
  int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
    int size = vals.size();

    graph.resize(size);
    parents.resize(size);

    map<int, vector<int>> valuesToNodes;
    for (int node = 0; node < size; node++) {
      valuesToNodes[vals[node]].push_back(node);
      parents[node] = node;
    }

    for (vector<int> &e : edges) {
      int a = e.front(), b = e.back();

      graph[b].push_back(a);
      graph[a].push_back(b);
    }

    int answer = 0;
    for (auto &[value, nodes] : valuesToNodes) {
      for (int node : nodes) {
        for (int next : graph[node]) {
          if (vals[node] < vals[next]) continue;
          merge(node, next);
        }
      }

      unordered_map<int, int> group;
      for (int node : nodes) {
        group[find(node)]++;
      }

      for (auto &[_, size] : group) {
        answer += (size * (size + 1) / 2);
      }
    }

    return answer;
  }
};
