#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define MAX 987654321

using namespace std;

struct Edge {
  int to, cost;
};

struct Status {
  Edge edge;

  bool operator<(const Status &s) const {
    return edge.cost > s.edge.cost;
  }
};

int N, M;
int costToTarget[1001];
int costFromTarget[1001];
vector<Edge> toGraph[1001];
vector<Edge> fromGraph[1001];

void dijkstra(int start, vector<Edge> graph[], int *costs) {
  priority_queue<Status> pq;

  fill(costs, costs + N + 1, MAX);
  costs[start] = 0;

  pq.push({start, 0});
  while (!pq.empty()) {
    Status cur = pq.top();
    Edge edge = cur.edge;
    pq.pop();

    for (Edge next : graph[edge.to]) {
      int new_val = costs[edge.to] + next.cost;
      int before_val = costs[next.to];

      if (new_val < before_val) {
        costs[next.to] = new_val;
        pq.push({next.to, new_val});
      }
    }
  }
}

void solution() {
  int X;
  cin >> N >> M >> X;

  int from, to, cost;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;

    toGraph[from].push_back({to, cost});
    fromGraph[to].push_back({from, cost});
  }

  dijkstra(X, toGraph, costToTarget);
  dijkstra(X, fromGraph, costFromTarget);

  int answer = 0;
  for (int node = 1; node <= N; node++) {
    answer = max(answer, costFromTarget[node] + costToTarget[node]);
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