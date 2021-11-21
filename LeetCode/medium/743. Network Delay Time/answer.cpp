#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dijkstra

class Solution {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

 public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // graph[n + 1] = {edge{from, to, cost}, ...}
    vector<vector<Edge>> graph(n + 1);
    // change times data to graph
    for (vector<int> &time : times) {
      int from = time[0], to = time[1], cost = time[2];
      graph[from].push_back({from, to, cost});
    }
    // costs[n + 1] = INT_MAX; costs from k to node
    vector<int> costs(n + 1, INT_MAX);
    // setInitial value of costs. start's cost is 0
    costs[k] = 0;

    // use dijkstra algorithm to find costs of node (destination)
    // we use priority queue
    // priority queue<Edge> pq
    priority_queue<Edge> pq;
    // insert start's edge into pq
    // and update costs of edge
    for (Edge &edge : graph[k]) {
      pq.push(edge);
      costs[edge.to] = edge.cost;
    }

    // do it until pq is not empty
    while (!pq.empty()) {
      // pop current edge
      Edge cur = pq.top();
      pq.pop();

      // iterate next edge's from current node
      for (Edge &edge : graph[cur.to]) {
        // compare new value, before value
        int newValue = costs[cur.to] + edge.cost;  // k ~ edge.from ~ edge.to
        int beforeValue = costs[edge.to];          // k ~ edge.to

        // if new value < before value update and push edge
        if (newValue < beforeValue) {
          costs[edge.to] = newValue;
          pq.push(edge);
        }
      }
    }

    // check there are unvisited nodes. if it is return -1
    int answer = 0;
    for (int i = 1; i <= n; i++) {
      int cost = costs[i];

      if (cost == INT_MAX) return -1;
      answer = max(answer, cost);
    }
    // return maximum value of costs
    return answer;
  }
};