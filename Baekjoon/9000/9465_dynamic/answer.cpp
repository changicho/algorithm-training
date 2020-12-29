#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;
int board[2][100000];
int dp[2][100001];

void solution() {
  memset(dp, 0, sizeof(dp));

  cin >> N;

  for (int y = 0; y < 2; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  // dp[0][x] = max(dp[1][x-1], dp[0][x-2] + board[0][x]);

  dp[0][0] = board[0][0];
  dp[1][0] = board[1][0];
  dp[0][1] = board[1][0] + board[0][1];
  dp[1][1] = board[0][0] + board[1][1];

  for (int x = 2; x < N; x++) {
    for (int y = 0; y < 2; y++) {
      int toggle = y == 0 ? 1 : 0;

      dp[y][x] = max(dp[toggle][x - 1], max(dp[0][x - 2], dp[1][x - 2])) + board[y][x];
    }
  }

  int answer = max(dp[0][N - 1], dp[1][N - 1]);
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    solution();
  }

  return 0;
}