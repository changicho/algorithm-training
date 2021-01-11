#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool board[100][100];

void solution() {
  int N, M;
  int cheeseCount = 0;

  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> board[y][x];
      cheeseCount += board[y][x];
    }
  }

  int answer = 0;
  while (cheeseCount != 0) {
    answer += 1;

    bool visited[100][100] = {
        false,
    };
    int count[100][100] = {
        0,
    };

    vector<Axis> deletes;
    queue<Axis> q;
    q.push({0, 0});

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (visited[cur.y][cur.x]) continue;
      visited[cur.y][cur.x] = true;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
        if (board[next.y][next.x] == 1) {
          if (count[next.y][next.x] < 1) {
            count[next.y][next.x] += 1;
          } else {
            deletes.push_back(next);
          }
          continue;
        }

        q.push(next);
      }
    }

    for (Axis target : deletes) {
      if (board[target.y][target.x] == true) {
        cheeseCount -= 1;
        board[target.y][target.x] = false;
      }
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