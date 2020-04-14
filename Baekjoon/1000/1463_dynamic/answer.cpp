#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[1000001];

// dp[n] = min(dp[n-1], dp[n/2], dp[n/3]) + 1
// 나누어 떨어지는 경우만

void dynamic() {
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
}

void solution() {
  int N;
  cin >> N;

  for (int i = 4; i <= N; i++) {
    int div = -1;
    if (i % 3 == 0) {
      div = dp[i / 3];
    } else if (i % 2 == 0) {
      div = dp[i / 2];
    }

    if (div == -1) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = min(dp[i - 1], div) + 1;
    }
  }

  cout << dp[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dynamic();
  solution();

  return 0;
}