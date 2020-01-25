#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321

using namespace std;

struct edge {
  int end, cost;
};

vector<edge> graph[501];
vector<int> costs;
int N, M;
bool isCycle;

void bellman_ford(int start_index) {
  // initialize
  for (int i = 1; i <= N; i++) {
    costs[i] = INF;
  }
  costs[start_index] = 0;

  isCycle = false;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      // current : 현재 간선
      for (edge current : graph[j]) {
        int new_val = costs[j] + current.cost;
        int before_val = costs[current.end];

        if (costs[j] != INF && before_val > new_val) {
          costs[current.end] = new_val;

          if (i == N) isCycle = true;
        }
      }
    }
  }
}

void solution() {
  cin >> N >> M;

  int start = 1;

  costs.resize(N + 1);
  while (M--) {
    int A, B, C;
    cin >> A >> B >> C;

    graph[A].push_back(edge{B, C});
  }

  bellman_ford(start);

  if (isCycle) {
    cout << "-1\n";
    return;
  }

  for (int i = 2; i <= N; i++) {
    if (costs[i] == INF)
      cout << "-1\n";
    else
      cout << costs[i] << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}