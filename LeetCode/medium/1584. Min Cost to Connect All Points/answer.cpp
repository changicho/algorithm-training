#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use prim's algorithm

class Solution {
 private:
  struct Edge {
    int to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; };
  };

  int getCost(vector<int> &a, vector<int> &b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

 public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int size = points.size();

    int answer = 0;
    priority_queue<Edge> pq;
    int start = 0;
    vector<bool> visited(size, false);
    visited[start] = true;

    for (int next = 0; next < size; next++) {
      if (visited[next]) continue;
      int cost = getCost(points[start], points[next]);
      pq.push({next, cost});
    }

    while (!pq.empty()) {
      Edge edge = pq.top();
      pq.pop();

      int cur = edge.to, cost = edge.cost;
      if (visited[cur]) continue;
      visited[cur] = true;
      answer += cost;

      for (int next = 0; next < size; next++) {
        if (visited[next]) continue;
        int cost = getCost(points[cur], points[next]);
        pq.push({next, cost});
      }
    }

    return answer;
  }
};

// use kruskal's algorithm

class Solution {
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost < b.cost; };
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

  int getCost(vector<int> &a, vector<int> &b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

 public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int size = points.size();
    vector<Edge> edges;

    parents.resize(size);
    for (int i = 0; i < size; i++) {
      parents[i] = i;
    }

    for (int from = 0; from < size; from++) {
      for (int to = 0; to < size; to++) {
        if (from == to) continue;

        int cost = getCost(points[from], points[to]);
        edges.push_back({from, to, cost});
      }
    }

    sort(edges.begin(), edges.end());

    int answer = 0;
    for (Edge &edge : edges) {
      if (find(edge.from) == find(edge.to)) continue;

      answer += edge.cost;
      merge(edge.from, edge.to);
    }

    return answer;
  }
};

// use prim more faster

class Solution {
 private:
  int getCost(vector<int> &a, vector<int> &b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

 public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int size = points.size();
    int answer = 0, node = 0;
    vector<int> distances(size, 10000000);

    int remain = size;
    while (--remain) {
      distances[node] = INT_MAX;
      int minIdx = node;

      for (int next = 0; next < size; ++next) {
        if (distances[next] == INT_MAX) continue;
        distances[next] =
            min(distances[next], getCost(points[node], points[next]));

        if (distances[next] < distances[minIdx]) minIdx = next;
      }
      answer += distances[minIdx];
      node = minIdx;
    }

    return answer;
  }
};