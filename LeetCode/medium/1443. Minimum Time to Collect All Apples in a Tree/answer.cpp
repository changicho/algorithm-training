#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(E + N)
// space : O(E + N)
class Solution {
 private:
  vector<vector<int>> graph;
  vector<bool> hasApple;
  vector<bool> visited;
  vector<int> countApple;

  int answer = 0;

  int recursiveCountApple(int node) {
    visited[node] = true;

    int ret = 0;
    if (hasApple[node]) ret += 1;

    for (int &next : graph[node]) {
      if (visited[next]) continue;

      ret += recursiveCountApple(next);
    }

    return countApple[node] = ret;
  }

  void recursive(int node) {
    visited[node] = true;

    if (countApple[node] == 0) {
      return;
    }

    for (int &next : graph[node]) {
      if (visited[next]) continue;
      if (countApple[next] == 0) continue;

      answer++;
      recursive(next);
      answer++;
    }
  }

 public:
  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
    this->hasApple = hasApple;

    graph.resize(n);
    visited.resize(n);
    countApple.resize(n);
    for (vector<int> &e : edges) {
      int a = e.front(), b = e.back();
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    recursiveCountApple(0);

    for (int i = 0; i < n; i++) {
      visited[i] = false;
    }
    recursive(0);

    return answer;
  }
};