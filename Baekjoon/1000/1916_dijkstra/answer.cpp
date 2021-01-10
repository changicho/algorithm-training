#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define INF 100000001

using namespace std;

struct Edge {
  int to, cost;

  bool operator<(const Edge &b) const {
    return cost > b.cost;
  }
};

vector<vector<Edge> > graph;
vector<int> costs;

void solution() {
  int N, M;

  cin >> N >> M;

  graph.resize(N + 1);
  costs.resize(N + 1, INF);

  int from, to, cost;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
  }
  cin >> from >> to;

  priority_queue<Edge> pq;
  pq.push({from, 0});
  costs[from] = 0;

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Edge next : graph[cur.to]) {
      int new_value = costs[cur.to] + next.cost;
      int before_value = costs[next.to];

      if (new_value < before_value) {
        costs[next.to] = new_value;

        pq.push({next.to, new_value});
      }
    }
  }

  int answer = costs[to];
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}