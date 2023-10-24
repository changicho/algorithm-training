#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

long long convert(Axis a) { return a.y * 10000 + a.x; }

int solution(vector<vector<char>> &board) {
  int rows = board.size(), cols = board[0].size();
  int alreadyCaptured = 0;
  int answer = 0;

  unordered_map<long long, int> capturedCount;
  unordered_set<long long> visited;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] != 'W') continue;
      if (visited.count(convert({y, x})) > 0) continue;
      queue<Axis> q;

      q.push({y, x});
      visited.insert(convert({y, x}));
      Axis point = {-1, -1};

      unordered_map<char, int> border;
      unordered_set<long long> borderCheck;

      int count = 0;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();
        count++;

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (visited.count(convert(next)) > 0) continue;

          if (!borderCheck.count(convert(next))) {
            borderCheck.insert(convert(next));
            border[board[next.y][next.x]]++;
            if (board[next.y][next.x] == '.') point = next;
          }

          if (board[next.y][next.x] != 'W') continue;
          visited.insert(convert(next));

          q.push(next);
        }
      }

      if (border['.'] > 1) {
        count = 0;
        point = {-1, -1};
      }

      if (count == 0) continue;
      if (point.y == -1) {
        alreadyCaptured += count;
      } else {
        capturedCount[convert(point)] += count;
        answer = max(alreadyCaptured + capturedCount[convert(point)], answer);
      }
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);
  freopen("./ready_go_part_2_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int R, C;
    cin >> R >> C;

    vector<vector<char>> board(R, vector<char>(C));

    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        cin >> board[y][x];
      }
    }
    int answer = solution(board);

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}