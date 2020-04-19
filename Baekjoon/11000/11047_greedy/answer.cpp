#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, K, answer = 0;

  cin >> N >> K;

  vector<int> coins(N);

  for (int i = 0; i < N; i++) {
    cin >> coins[i];
  }

  for (int i = N - 1; i >= 0; i -= 1) {
    if (coins[i] > K) {
      continue;
    }

    while (K >= coins[i]) {
      K -= coins[i];
      answer += 1;
    }
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