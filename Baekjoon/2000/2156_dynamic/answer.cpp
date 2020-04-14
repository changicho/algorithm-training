#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[10001];

void solution() {
  int N, answer = 0;
  cin >> N;

  vector<int> wine(N, 0);

  for (int i = 0; i < N; i++) {
    cin >> wine[i];
  }

  dp[0] = wine[0];
  dp[1] = wine[0] + wine[1];
  dp[2] = max(wine[0] + wine[1], max(wine[1], wine[0]) + wine[2]);

  for (int i = 0; i < 3; i++) {
    answer = max(answer, dp[i]);
  }

  for (int i = 3; i < N; i++) {
    dp[i] = max(dp[i - 3] + wine[i - 1], dp[i - 2]) + wine[i];
    dp[i] = max(dp[i - 1], dp[i]);

    answer = max(answer, dp[i]);
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