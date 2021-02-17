#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  double y, x;
};

struct Edge {
  int vertex;
  double cost;
};

struct Status {
  Edge edge;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};

vector<vector<Edge>> graph;

double getCost(Axis a, Axis b) {
  double y_cost = (a.y - b.y) * (a.y - b.y);
  double x_cost = (a.x - b.x) * (a.x - b.x);
  return sqrt(y_cost + x_cost);
}

void solution() {
  int N;
  cin >> N;

  graph.resize(N + 1);
  priority_queue<Status> pq;
  vector<bool> visited(N + 1, false);
  vector<Axis> points(N);

  for (int i = 0; i < N; i++) {
    cin >> points[i].y >> points[i].x;
  }

  for (int from = 0; from < N; from++) {
    for (int to = 0; to < N; to++) {
      if (from == to) continue;

      double cost = getCost(points[from], points[to]);
      graph[from].push_back({to, cost});
    }
  }

  visited[1] = true;
  for (Edge cur : graph[1]) {
    pq.push({cur});
  }

  double answer = 0;

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();
    Edge edge = cur.edge;

    if (visited[edge.vertex]) continue;
    visited[edge.vertex] = true;

    answer += edge.cost;

    for (Edge next : graph[edge.vertex]) {
      pq.push({next});
    }
  }
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(2);

  solution();

  return 0;
}