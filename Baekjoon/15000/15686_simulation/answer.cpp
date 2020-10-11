#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int getDistance(Axis a, Axis b) {
  return abs(a.y - b.y) + abs(a.x - b.x);
}

void solution() {
  int N, M;
  cin >> N >> M;
  int answer = 50 * 50 * 13;

  vector<Axis> chickens;
  vector<Axis> homes;

  int board[50][50];
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];

      if (board[y][x] == 1) {
        homes.push_back({y, x});
      }
      if (board[y][x] == 2) {
        chickens.push_back({y, x});
      }
    }
  }

  vector<bool> visited(chickens.size(), false);
  for (int i = 0; i < M; i++) {
    visited[i] = true;
  }
  sort(visited.begin(), visited.end());

  do {
    int totalDistance = 0;
    for (Axis home : homes) {
      int count = 50 * 50;

      for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) continue;

        count = min(count, getDistance(home, chickens[i]));
      }
      totalDistance += count;
    }

    answer = min(answer, totalDistance);
  } while (next_permutation(visited.begin(), visited.end()));

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}