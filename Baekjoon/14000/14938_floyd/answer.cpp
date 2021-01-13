#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define MAX 987654321

using namespace std;

void solution() {
  vector<int> scores;
  int graph[101][101] = {
      0,
  };
  int N, M, R;
  cin >> N >> M >> R;

  scores.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> scores[i];
  }

  for (int y = 1; y <= N; y++) {
    for (int x = 1; x <= N; x++) {
      graph[y][x] = y == x ? 0 : MAX;
    }
  }

  int from, to, cost;
  for (int i = 0; i < R; i++) {
    cin >> from >> to >> cost;

    graph[from][to] = cost;
    graph[to][from] = cost;
  }

  for (int through = 1; through <= N; through++) {
    for (int from = 1; from <= N; from++) {
      for (int to = 1; to <= N; to++) {
        graph[from][to] = min(graph[from][to], graph[from][through] + graph[through][to]);
      }
    }
  }

  int answer = 0;
  for (int node = 1; node <= N; node++) {
    int score = 0;

    for (int next = 1; next <= N; next++) {
      if (graph[node][next] <= M) {
        score += scores[next];
      }
    }

    answer = max(answer, score);
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