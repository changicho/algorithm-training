#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  double W, L, D;
  double dp[21][3001] = {
      0,
  };
  double rankCount[5] = {
      0,
  };

  cin >> W >> L >> D;

  dp[0][2000] = 1;
  for (int gameCount = 1; gameCount <= 20; gameCount++) {
    for (int score = 1000; score <= 3000; score++) {
      if (dp[gameCount - 1][score] == 0) continue;

      dp[gameCount][score - 50] += dp[gameCount - 1][score] * L;
      dp[gameCount][score + 50] += dp[gameCount - 1][score] * W;
      dp[gameCount][score] += dp[gameCount - 1][score] * D;
    }
  }

  for (int score = 1000; score <= 3000; score++) {
    if (1000 <= score && score <= 1499) {
      rankCount[0] += dp[20][score];
    } else if (1500 <= score && score <= 1999) {
      rankCount[1] += dp[20][score];
    } else if (2000 <= score && score <= 2499) {
      rankCount[2] += dp[20][score];
    } else if (2500 <= score && score <= 2999) {
      rankCount[3] += dp[20][score];
    } else {
      rankCount[4] += dp[20][score];
    }
  }

  for (double count : rankCount) {
    cout << count << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(8);
  cout << fixed;

  solution();

  return 0;
}