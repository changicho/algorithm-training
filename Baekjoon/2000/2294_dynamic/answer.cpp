#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define INF 10001

using namespace std;

int dp[10001];

void solution() {
  int N, K;
  int answer;

  fill(&dp[0], &dp[10001], INF);
  dp[0] = 0;

  cin >> N >> K;
  vector<int> coins(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> coins[i];

    for (int j = coins[i]; j <= K; j++) {
      dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    }
  }

  answer = dp[K];
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