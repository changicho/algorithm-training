#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321

using namespace std;

struct edge {
  long long end, cost;
};

vector<edge> graph[501];
long long costs[501];

void solution() {
  int N, M;
  int start = 1;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;

    graph[A].push_back(edge{B, C});
  }

  // initialize
  for (int i = 1; i <= N; i++) {
    costs[i] = INF;
  }

  costs[start] = 0;
  bool isCycle = false;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (edge g : graph[j]) {
        if (costs[j] != INF && costs[g.end] > g.cost + costs[j]) {
          costs[g.end] = g.cost + costs[j];

          if (i == N) isCycle = true;
        }
      }
    }
  }

  if (isCycle) {
    cout << "-1\n";
    return;
  }

  for (int i = 2; i <= N; i++) {
    cout << (costs[i] == INF ? -1 : costs[i]) << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./data/input.txt", "r", stdin);

  solution();

  return 0;
}