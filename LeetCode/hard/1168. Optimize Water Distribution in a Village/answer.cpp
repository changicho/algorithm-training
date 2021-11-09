#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use MST (prim's algorithm)

class Solution {
 private:
  struct Edge {
    int to, cost;
  };

  struct Status {
    Edge edge;

    bool operator<(const Status& b) const { return edge.cost > b.edge.cost; }
  };

 public:
  int minCostToSupplyWater(int n, vector<int>& wells,
                           vector<vector<int>>& pipes) {
    priority_queue<Status> pq;
    vector<bool> visited(n + 1, false);
    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < wells.size(); i++) {
      graph[0].push_back({i + 1, wells[i]});
    }

    int answer = 0;
    for (vector<int>& pipe : pipes) {
      int from = pipe[0], to = pipe[1], cost = pipe[2];

      graph[from].push_back({to, cost});
      graph[to].push_back({from, cost});
    }

    for (Edge cur : graph[0]) {
      pq.push({cur});
    }

    while (!pq.empty()) {
      Status cur = pq.top();
      pq.pop();
      Edge edge = cur.edge;

      if (visited[edge.to]) continue;
      visited[edge.to] = true;

      answer += edge.cost;

      for (Edge next : graph[edge.to]) {
        pq.push({next});
      }
    }
    return answer;
  }
};

// use MST (kruskal's algorithm)

class Solution {
 private:
  struct Edge {
    int from, to, weight;

    bool const operator<(const Edge& b) const { return weight < b.weight; }
  };
  vector<int> parents;

  int find(int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    int parentA = find(a), parentB = find(b);

    if (parentA > parentB) swap(parentA, parentB);
    parents[parentB] = parentA;
  }

 public:
  int minCostToSupplyWater(int n, vector<int>& wells,
                           vector<vector<int>>& pipes) {
    vector<Edge> edges;

    parents.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parents[i] = i;
    }

    for (int i = 0; i < wells.size(); i++) {
      edges.push_back({0, i + 1, wells[i]});
    }
    for (vector<int>& pipe : pipes) {
      edges.push_back({pipe[0], pipe[1], pipe[2]});
    }

    sort(edges.begin(), edges.end());
    int answer = 0;

    for (Edge edge : edges) {
      if (find(edge.from) == find(edge.to)) continue;

      merge(edge.from, edge.to);
      answer += edge.weight;
    }

    return answer;
  }
};