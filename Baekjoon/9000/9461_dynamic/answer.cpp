#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[101];

void dynamic() {
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = 2;
  for (int i = 5; i <= 100; i++) {
    dp[i] = dp[i - 2] + dp[i - 3];
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

  dynamic();

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}