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

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Energy {
  int y, x, e;

  const bool operator<(const Energy &energy) const { return e < energy.e; }
};

// .: An empty cell.
// #: An obstacle.
// S: An empty cell and the start point.
// T: An empty cell and the goal point.

Axis getTarget(vector<string> &board, char target) {
  int rows = board.size();
  int cols = board[0].size();
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == target) {
        return {y, x};
      }
    }
  }

  return {-1, -1};
}

bool solution(int rows, int cols, vector<string> &board,
              vector<Energy> &energies) {
  vector<vector<int>> dp(rows, vector<int>(cols, -1));
  vector<vector<int>> eBoard(rows, vector<int>(cols, 0));

  for (Energy &energy : energies) {
    eBoard[energy.y - 1][energy.x - 1] = energy.e;
  }

  Axis start = getTarget(board, 'S');
  Axis gaol = getTarget(board, 'T');

  int startEnergy = eBoard[start.y][start.x];

  priority_queue<Energy> pq;

  if (startEnergy > 0) {
    dp[start.y][start.x] = startEnergy;
    pq.push({start.y, start.x, startEnergy});
  }

  while (!pq.empty()) {
    Energy cur = pq.top();
    pq.pop();

    if (cur.y == gaol.y && cur.x == gaol.x) {
      return true;
    }
    if (cur.e <= 0) {
      continue;
    }

    for (Axis dir : dirs) {
      int ny = cur.y + dir.y;
      int nx = cur.x + dir.x;

      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
        continue;
      }
      if (board[ny][nx] == '#') {
        continue;
      }

      int ne = cur.e - 1;
      if (ne < eBoard[ny][nx]) {
        ne = eBoard[ny][nx];
        eBoard[ny][nx] = 0;
      }

      if (ne > dp[ny][nx]) {
        dp[ny][nx] = ne;
        pq.push({ny, nx, ne});
      }
    }
  }

  return false;
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

  int N;
  cin >> N;

  vector<Energy> energies(N);
  for (int i = 0; i < N; i++) {
    cin >> energies[i].y >> energies[i].x >> energies[i].e;
  }

  bool answer = solution(H, W, board, energies);

  cout << (answer ? "Yes" : "No") << endl;

  return 0;
}