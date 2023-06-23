#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getScore(vector<vector<int>> &board, Axis start) {
  int rows = board.size(), cols = board[0].size();

  queue<Axis> q;
  q.push(start);

  int score = 0;
  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (board[cur.y][cur.x] == 1) continue;
    score += board[cur.y][cur.x] == 0 ? 1 : -2;
    board[cur.y][cur.x] = 1;

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] == 1) continue;

      q.push(next);
    }
  }

  return score;
}

int solution(vector<vector<int>> &board) {
  int rows = board.size(), cols = board[0].size();

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 1) continue;

      int curScore = getScore(board, {y, x});
      answer = max(curScore, answer);
    }
  }

  return answer;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> board(N, vector<int>(M));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> board[y][x];
    }
  }

  int answer = solution(board);
  cout << answer << endl;

  return 0;
}