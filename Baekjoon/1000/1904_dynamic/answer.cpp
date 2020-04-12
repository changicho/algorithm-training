#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define DIV 15746

// N ≤ 1,000,000

using namespace std;

int dp[1000001];

void solution() {
  int N;
  cin >> N;

  for (int i = 3; i <= N; i++) {
    dp[i] = dp[i - 1] % DIV + dp[i - 2] % DIV;
    dp[i] = dp[i] % DIV;
  }

  cout << dp[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  dp[4] = 5;

  solution();

  return 0;
}