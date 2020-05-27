#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define INF 10000

using namespace std;

int dp[101][10001];

void solution() {
  int N, K;
  int answer;

  cin >> N >> K;
  fill(&dp[0][0], &dp[100][10001], INF);

  vector<int> coins(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> coins[i];

    if (coins[i] < 10001) {
      dp[i][coins[i]] = 1;
    }
  }

  for (int i = 1; i < coins.size(); i++) {
    int coin = coins[i];

    for (int k = 1; k <= K; k++) {
      if (k - coin < 0) {
        dp[i][k] = min(dp[i][k], dp[i - 1][k]);
        continue;
      }

      dp[i][k] = min(dp[i][k], min(dp[i - 1][k], dp[i][k - coin] + 1));
    }
  }

  answer = dp[N][K];
  if (answer >= INF) {
    answer = -1;
  }
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}