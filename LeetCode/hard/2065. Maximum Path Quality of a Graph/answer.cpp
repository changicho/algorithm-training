#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use DFS (visited count)

class Solution {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

  vector<vector<Edge>> graph;
  vector<int> visited;
  int answer;

  void dfs(int node, int sum, int cost, int maxTime, vector<int> &values) {
    if (cost > maxTime) return;

    if (visited[node] == 0) sum += values[node];
    visited[node]++;

    if (node == 0) {
      answer = max(answer, sum);
    }

    for (Edge &next : graph[node]) {
      dfs(next.to, sum, cost + next.cost, maxTime, values);
    }

    visited[node]--;
  }

 public:
  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                         int maxTime) {
    int size = values.size();
    visited.resize(size, 0);
    graph.resize(size);
    for (vector<int> &edge : edges) {
      int from = edge[0], to = edge[1], cost = edge[2];

      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost});
    }

    answer = values[0];

    dfs(0, 0, 0, maxTime, values);

    return answer;
  }
};

// use DFS (visited count) with dijkstra

class Solution {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

  vector<vector<Edge>> graph;
  vector<int> visited;
  vector<int> costs;
  int answer;

  void dfs(int node, int sum, int cost, int maxTime, vector<int> &values) {
    if (cost > maxTime) return;

    if (visited[node] == 0) sum += values[node];
    visited[node]++;

    if (node == 0) {
      answer = max(answer, sum);
    }

    for (Edge &next : graph[node]) {
      if (cost + next.cost + costs[next.to] > maxTime) continue;

      dfs(next.to, sum, cost + next.cost, maxTime, values);
    }

    visited[node]--;
  }

 public:
  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                         int maxTime) {
    int size = values.size();

    visited.resize(size, 0);
    graph.resize(size);
    for (vector<int> &edge : edges) {
      int from = edge[0], to = edge[1], cost = edge[2];

      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost});
    }

    costs.resize(size, INT_MAX);  // all cost from 0;
    priority_queue<Edge> pq;
    for (Edge &next : graph[0]) {
      pq.push(next);
    }
    costs[0] = 0;

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      if (cur.cost >= costs[cur.to]) continue;
      costs[cur.to] = cur.cost;

      for (Edge &next : graph[cur.to]) {
        pq.push({next.from, next.to, next.cost + cur.cost});
      }
    }

    answer = values[0];

    dfs(0, 0, 0, maxTime, values);

    return answer;
  }
};