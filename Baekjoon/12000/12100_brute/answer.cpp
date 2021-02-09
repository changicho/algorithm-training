#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N;

int findMax(vector<vector<int>> board) {
  int ret = board[0][0];
  for (vector<int> line : board) {
    for (int num : line) {
      ret = max(ret, num);
    }
  }
  return ret;
}

vector<vector<int>> move_up(vector<vector<int>> board) {
  vector<vector<bool>> visited(N, vector<bool>(N, false));

  for (int x = 0; x < N; x += 1) {
    for (int y = 1; y < N; y += 1) {
      if (board[y][x] == 0) continue;

      for (int cur = y; cur > 0; cur -= 1) {
        int next = cur - 1;
        if (next < 0) break;

        if (board[next][x] == 0) {
          board[next][x] = board[cur][x];
          board[cur][x] = 0;
        } else if (board[next][x] == board[cur][x] && !visited[next][x]) {
          board[next][x] += board[cur][x];
          board[cur][x] = 0;
          visited[next][x] = true;
          break;
        } else {
          break;
        }
      }
    }
  }
  return board;
}

vector<vector<int>> move_down(vector<vector<int>> board) {
  vector<vector<bool>> visited(N, vector<bool>(N, false));

  for (int x = 0; x < N; x += 1) {
    for (int y = N - 1; y >= 0; y -= 1) {
      if (board[y][x] == 0) continue;

      for (int cur = y; cur < N; cur += 1) {
        int next = cur + 1;
        if (next >= N) break;

        if (board[next][x] == 0) {
          board[next][x] = board[cur][x];
          board[cur][x] = 0;
        } else if (board[next][x] == board[cur][x] && !visited[next][x]) {
          board[next][x] += board[cur][x];
          board[cur][x] = 0;
          visited[next][x] = true;
          break;
        } else {
          break;
        }
      }
    }
  }
  return board;
}

vector<vector<int>> move_left(vector<vector<int>> board) {
  vector<vector<bool>> visited(N, vector<bool>(N, false));

  for (int y = 0; y < N; y += 1) {
    for (int x = 0; x < N; x += 1) {
      if (board[y][x] == 0) continue;

      for (int cur = x; cur >= 0; cur -= 1) {
        int next = cur - 1;
        if (next < 0) break;

        if (board[y][next] == 0) {
          board[y][next] = board[y][cur];
          board[y][cur] = 0;
        } else if (board[y][next] == board[y][cur] && !visited[y][next]) {
          board[y][next] += board[y][cur];
          board[y][cur] = 0;
          visited[y][next] = true;
          break;
        } else {
          break;
        }
      }
    }
  }
  return board;
}

vector<vector<int>> move_right(vector<vector<int>> board) {
  vector<vector<bool>> visited(N, vector<bool>(N, false));

  for (int y = 0; y < N; y += 1) {
    for (int x = N - 1; x >= 0; x -= 1) {
      if (board[y][x] == 0) continue;

      for (int cur = x; cur < N; cur += 1) {
        int next = cur + 1;
        if (next >= N) break;

        if (board[y][next] == 0) {
          board[y][next] = board[y][cur];
          board[y][cur] = 0;
        } else if (board[y][next] == board[y][cur] && !visited[y][next]) {
          board[y][next] += board[y][cur];
          board[y][cur] = 0;
          visited[y][next] = true;
          break;
        } else {
          break;
        }
      }
    }
  }
  return board;
}

struct Status {
  vector<vector<int>> board;
  int step;
};

void solution() {
  cin >> N;

  vector<vector<int>> board(N, vector<int>(N));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  int answer = 0;

  queue<Status> q;
  q.push({board, 0});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.step == 5) {
      answer = max(answer, findMax(cur.board));
      continue;
    }

    q.push({move_up(cur.board), cur.step + 1});
    q.push({move_down(cur.board), cur.step + 1});
    q.push({move_left(cur.board), cur.step + 1});
    q.push({move_right(cur.board), cur.step + 1});
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