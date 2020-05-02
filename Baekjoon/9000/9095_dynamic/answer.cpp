#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[11];

void init() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 4; i <= 10; i++) {
    dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
  }
}

void solution() {
  int N;
  cin >> N;

  cout << dp[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  init();
  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}