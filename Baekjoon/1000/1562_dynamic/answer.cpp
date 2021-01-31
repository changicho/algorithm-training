#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000000

using namespace std;

void solution() {
  int N;
  int answer = 0;
  int dp[101][10][1 << 10] = {
      0,
  };

  cin >> N;

  for (int number = 1; number <= 9; ++number) {
    dp[1][number][1 << number] = 1;
  }

  for (int depth = 2; depth <= N; depth++) {
    for (int number = 0; number <= 9; number++) {
      for (int digit = 0; digit <= (1 << 10) - 1; digit++) {
        if (number != 0) {
          dp[depth][number][digit | (1 << number)] += dp[depth - 1][number - 1][digit];
          dp[depth][number][digit | (1 << number)] %= MOD;
        }

        if (number != 9) {
          dp[depth][number][digit | (1 << number)] += dp[depth - 1][number + 1][digit];
          dp[depth][number][digit | (1 << number)] %= MOD;
        }
      }
    }
  }

  for (int number = 0; number <= 9; number++) {
    answer = (answer + dp[N][number][(1 << 10) - 1]) % MOD;
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