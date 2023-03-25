#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// use BFS
// time : O(N + E)
// space : O(N + E)
class Solution {
 private:
  struct Edge {
    int from, to, cost;
  };

 public:
  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<Edge>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    int answer = INT_MAX;

    for (vector<int> &road : roads) {
      int a = road[0], b = road[1], dist = road[2];

      graph[a].push_back({a, b, dist});
      graph[b].push_back({b, a, dist});
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      if (visited[cur]) continue;
      visited[cur] = true;

      for (Edge &e : graph[cur]) {
        q.push(e.to);
        answer = min(answer, e.cost);
      }
    }

    return answer;
  }
};

// use union find
// time : O(N + E)
// space : O(N)
class Solution {
 private:
  vector<int> parents;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);

    parents[b] = a;
  }

 public:
  int minScore(int n, vector<vector<int>> &roads) {
    parents.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      parents[i] = i;
    }
    int answer = INT_MAX;
    for (vector<int> &road : roads) {
      int a = road[0], b = road[1], dist = road[2];

      merge(a, b);
    }

    for (vector<int> &road : roads) {
      int a = road[0], b = road[1], dist = road[2];
      if (find(a) == 1) {
        answer = min(answer, dist);
      }
    }
    return answer;
  }
};