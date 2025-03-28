#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
  vector<bool> visited(1e6 + 1, false);
  unordered_map<int, vector<int>> graph;

  for (vector<int>& edge : edges) {
    int a = edge[0], b = edge[1];

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  function<pair<bool, bool>(int)> bfs = [&](int start) -> pair<bool, bool> {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int forwardChance = 0;
    int reverseChance = 0;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      int children = graph[node].size();

      if ((node + children) % 2 == 0) {
        forwardChance++;
      } else {
        reverseChance++;
      }

      for (int& next : graph[node]) {
        if (!visited[next]) {
          visited[next] = true;

          q.push(next);
        }
      }
    }

    bool isForward = forwardChance == 1, isReverse = reverseChance == 1;

    return {isForward, isReverse};
  };

  int forwardCount = 0, reverseCount = 0;
  for (int& node : nodes) {
    if (visited[node]) continue;
    auto [forward, reverse] = bfs(node);

    if (forward) forwardCount++;
    if (reverse) reverseCount++;
  }

  return {forwardCount, reverseCount};
}
