#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define DIV 1000000000

using namespace std;

int dp[101];
int table[10] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 1};

void dynamic() {
  dp[1] = 9;

  int current_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int before_count[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  for (int n = 2; n <= 100; n++) {
    for (int i = 0; i < 10; i++) {
      if (i - 1 >= 0) {
        current_count[i - 1] += before_count[i];
        current_count[i - 1] %= DIV;
      }
      if (i + 1 < 10) {
        current_count[i + 1] += before_count[i];
        current_count[i - 1] %= DIV;
      }
    }

    for (int i = 0; i < 10; i++) {
      dp[n] = dp[n] % DIV + (current_count[i] % DIV);
      dp[n] %= DIV;
    }

    for (int i = 0; i < 10; i++) {
      before_count[i] = current_count[i];
    }
    for (int i = 0; i < 10; i++) {
      current_count[i] = 0;
    }
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
  solution();

  return 0;
}