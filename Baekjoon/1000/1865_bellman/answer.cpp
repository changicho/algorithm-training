#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INF 2000000000

using namespace std;

struct Line {
  int to, cost;
};

vector<vector<Line> > graph;
vector<int> costs;
int N, M, W;

bool bellman_ford(int start_index) {
  for (int i = 1; i <= N; i++) {
    costs[i] = INF;
  }
  costs[start_index] = 0;

  for (int from = 1; from <= N; from++) {
    for (int to = 1; to <= N; to++) {
      for (Line current : graph[to]) {
        int new_val = costs[to] + current.cost;
        int before_val = costs[current.to];

        if (before_val > new_val) {
          costs[current.to] = new_val;

          if (from == N) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

void solution() {
  cin >> N >> M >> W;

  graph.resize(N + 1);
  costs.resize(N + 1, INF);

  int S, E, T;
  for (int i = 0; i < M; i++) {
    cin >> S >> E >> T;
    graph[S].push_back({E, T});
    graph[E].push_back({S, T});
  }

  for (int i = 0; i < W; i++) {
    cin >> S >> E >> T;
    graph[S].push_back({E, -T});
  }

  bool isCycle = bellman_ford(1);

  if (isCycle) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

void init() {
  graph.resize(0);
  costs.resize(0);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    init();
    solution();
  }

  return 0;
}