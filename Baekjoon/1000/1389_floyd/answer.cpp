#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 101

using namespace std;

int costs[101][101];

void solution() {
  int N, M;
  int sums[101] = {
      0,
  };
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      costs[i][j] = i == j ? 0 : MAX;
    }
  }

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    costs[from][to] = 1;
    costs[to][from] = 1;
  }

  for (int through = 1; through <= N; through++) {
    for (int from = 1; from <= N; from++) {
      for (int to = 1; to <= N; to++) {
        costs[from][to] = min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      sums[i] += costs[i][j];
    }
  }

  int answer = 1;
  for (int index = 1; index <= N; index++) {
    if (sums[index] < sums[answer]) answer = index;
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