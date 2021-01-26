#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INF 100000

using namespace std;

void solution() {
  long long dp[8] = {
      0,
  };
  long long D;
  cin >> D;

  dp[0] = 1;
  while (D--) {
    long long temp[8] = {
        0,
    };

    for (int i = 0; i < 8; i++) {
      temp[0] = dp[1] + dp[3];
      temp[1] = dp[0] + dp[2] + dp[3];
      temp[2] = dp[1] + dp[3] + dp[4] + dp[5];
      temp[3] = dp[0] + dp[1] + dp[2] + dp[5];
      temp[4] = dp[2] + dp[5] + dp[6];
      temp[5] = dp[3] + dp[2] + dp[4] + dp[7];
      temp[6] = dp[4] + dp[7];
      temp[7] = dp[5] + dp[6];
    }

    for (int i = 0; i < 8; i++) {
      dp[i] = temp[i] % 1000000007;
    }
  }

  cout << dp[0] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}