#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int towers[10010];
long long dp[2][10010];

void solution() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> towers[i];

    if (towers[i] != -1) towers[i] += 1;
  }

  int toggle = 1;  // it means toggle 1 > 0 > 1
  dp[0][1] = (towers[0] == -1 || towers[0] == 1) ? 1 : 0;

  for (int i = 1; i < N; i++, toggle = 1 - toggle) {
    memset(dp[toggle], 0, sizeof(dp[toggle]));

    if (towers[i] == -1) {
      for (int j = 1; j <= N; ++j) {
        dp[toggle][j] =
            dp[1 - toggle][j - 1] + dp[1 - toggle][j] + dp[1 - toggle][j + 1];
        dp[toggle][j] %= MOD;
      }
    } else {
      dp[toggle][towers[i]] = dp[1 - toggle][towers[i] - 1] +
                              dp[1 - toggle][towers[i]] +
                              dp[1 - toggle][towers[i] + 1];
      dp[toggle][towers[i]] %= MOD;
    }
  }

  cout << dp[1 - toggle][1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}