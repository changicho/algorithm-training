#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
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

// U R D L
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

unordered_map<int, char> dirToChar = {
    {0, 'U'},
    {1, 'R'},
    {2, 'D'},
    {3, 'L'},
};

string answer = "";
bool dp[1000][1000][4] = {
    false,
};  // y, x, dir

void recursive(vector<string>& board, Axis cur, string& path, int dir) {
  int rows = board.size(), cols = board[0].size();

  if (answer.size() > 0) {
    return;
  }

  if (dp[cur.y][cur.x][dir]) {
    return;
  }
  dp[cur.y][cur.x][dir] = true;

  if (board[cur.y][cur.x] == 'G') {
    answer = path;
    return;
  }

  for (int d = 0; d < 4; d++) {
    if (board[cur.y][cur.x] == 'o' && d != dir) {
      continue;
    } else if (board[cur.y][cur.x] == 'x' && d == dir) {
      continue;
    }
    Axis dd = dirs[d];
    Axis next = {cur.y + dd.y, cur.x + dd.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
      continue;
    }
    if (board[next.y][next.x] == '#') {
      continue;
    }
    path.push_back(dirToChar[d]);
    recursive(board, next, path, d);
    path.pop_back();
  }
}

// # : wall
// . : free
// o : ice must go same direction
// x : need to change direction
// S : start
// G : goal
string solution(int rows, int cols, vector<string>& board) {
  Axis start, goal;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'S') {
        start = {y, x};
      } else if (board[y][x] == 'G') {
        goal = {y, x};
      }
    }
  }

  for (int d = 0; d < 4; d++) {
    string path = "";
    recursive(board, start, path, d);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W;
  cin >> H >> W;

  vector<string> board(H);
  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }

  auto answer = solution(H, W, board);

  if (answer.size() == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << answer << endl;
  }
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}