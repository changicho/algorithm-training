#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define DIV 1000000

using namespace std;

// [날짜][지각횟수][연속결석]
int dp[1001][2][3];
int N;

void init() {
  dp[0][0][0] = 1;
  dp[1][0][0] = 1;
  dp[1][0][1] = 1;
  dp[1][1][0] = 1;
}

void solution() {
  int answer = 0;

  cin >> N;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j][0] += dp[i - 1][j][k];
        dp[i][j][0] %= DIV;

        // 결석 횟수가 3회 미만
        if (k + 1 < 3) {
          dp[i][j][k + 1] = dp[i - 1][j][k];
          dp[i][j][k + 1] %= DIV;
        }

        // 지각 횟수가 2회 미만
        if (j + 1 < 2) {
          dp[i][1][0] += dp[i - 1][0][k];
          dp[i][1][0] %= DIV;
        }
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      answer += dp[N][i][j];
    }
  }
  answer %= DIV;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();
  solution();

  return 0;
}