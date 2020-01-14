#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INF 987654321  // infinity

using namespace std;

int N, M;
int costs[101][101];

void floyd_warshall() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        if (costs[j][i] != INF && costs[i][k] != INF) {
          costs[j][k] = min(costs[j][k], costs[j][i] + costs[i][k]);
        }
      }
    }
  }

  // set self distance is 0;
  for (int i = 1; i <= N; i++) {
    costs[i][i] = 0;
  }
  return;
}

void solution() {
  cin >> N >> M;

  // initialize
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      costs[i][j] = INF;
    }
  }

  for (int i = 0; i < M; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;

    if (costs[from][to] > weight) costs[from][to] = weight;
  }

  floyd_warshall();

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (costs[i][j] == INF) {
        cout << 0 << " ";
        continue;
      }
      cout << costs[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}