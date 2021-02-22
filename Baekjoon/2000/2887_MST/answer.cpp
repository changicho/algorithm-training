#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int axis;
  int index;

  bool operator<(const Axis &b) const {
    return axis < b.axis;
  }
};

struct Edge {
  int to, cost;

  bool const operator<(const Edge &b) const {
    return cost < b.cost;
  }
};

struct Status {
  Edge edge;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};

void solution() {
  int N;
  cin >> N;

  vector<Axis> x_axis(N);
  vector<Axis> y_axis(N);
  vector<Axis> z_axis(N);

  for (int i = 0; i < N; i++) {
    cin >> x_axis[i].axis >> y_axis[i].axis >> z_axis[i].axis;
    x_axis[i].index = y_axis[i].index = z_axis[i].index = i;
  }

  sort(x_axis.begin(), x_axis.end());
  sort(y_axis.begin(), y_axis.end());
  sort(z_axis.begin(), z_axis.end());

  vector<vector<Edge>> graph(N);

  for (int i = 0; i < N - 1; i++) {
    graph[x_axis[i].index].push_back({x_axis[i + 1].index, x_axis[i + 1].axis - x_axis[i].axis});
    graph[x_axis[i + 1].index].push_back({x_axis[i].index, x_axis[i + 1].axis - x_axis[i].axis});

    graph[y_axis[i].index].push_back({y_axis[i + 1].index, y_axis[i + 1].axis - y_axis[i].axis});
    graph[y_axis[i + 1].index].push_back({y_axis[i].index, y_axis[i + 1].axis - y_axis[i].axis});

    graph[z_axis[i].index].push_back({z_axis[i + 1].index, z_axis[i + 1].axis - z_axis[i].axis});
    graph[z_axis[i + 1].index].push_back({z_axis[i].index, z_axis[i + 1].axis - z_axis[i].axis});
  }

  priority_queue<Status> pq;
  vector<bool> visited(N + 1, false);

  // 한 정점에서 시작하는 모든 간선을 우선순위 큐에 집어넣음
  visited[1] = true;
  for (Edge cur : graph[1]) {
    pq.push({cur});
  }

  int answer = 0;

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

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}