#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursive
// time : O(V + E)
// space : O(V + E)
class Solution {
 private:
  int answer = 0;

  vector<vector<int>> graph;
  vector<bool> visited;

  int recursive(int node) {
    visited[node] = true;

    int first = -1, second = -1;

    for (int &next : graph[node]) {
      if (visited[next]) continue;

      int len = recursive(next);
      if (len >= first) {
        second = first;
        first = len;
      } else if (len > second) {
        second = len;
      }
    }

    if (first == -1) {
      answer = max(answer, 1);
      return 1;
    }

    if (second != -1) {
      int sum = first + second;
      answer = max(answer, sum);
    }

    return first + 1;
  }

 public:
  int treeDiameter(vector<vector<int>> &edges) {
    if (edges.size() == 0) return 0;

    int size = edges.size() + 1;
    graph.resize(size);
    visited.resize(size, false);

    for (vector<int> &e : edges) {
      int from = e[0], to = e[1];

      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    recursive(0);

    return answer;
  }
};