#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS with backtracking

class Solution {
 private:
  void recursive(int node, vector<int> &path, vector<bool> &visited,
                 vector<vector<int>> &graph, vector<vector<int>> &answer) {
    int size = visited.size();

    path.push_back(node);

    if (visited[node]) return;
    visited[node] = true;

    if (node == size - 1) {
      answer.push_back(path);

      path.pop_back();
      visited[node] = false;
      return;
    }

    for (int next : graph[node]) {
      if (visited[next]) continue;

      recursive(next, path, visited, graph, answer);
    }

    visited[node] = false;
    path.pop_back();
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int size = graph.size();

    vector<vector<int>> answer;
    vector<bool> visited(size, false);
    vector<int> path;

    recursive(0, path, visited, graph, answer);

    return answer;
  }
};