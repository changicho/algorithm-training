#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DIV 10007

int dp[1001];

void init() {
  dp[1] = 1;
  dp[2] = 2;
}

void solution() {
  int N;
  cin >> N;

  for (int i = 3; i <= N; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] %= DIV;
  }

  cout << dp[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();
  solution();

  return 0;
}