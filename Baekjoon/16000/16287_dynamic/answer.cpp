#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int W, N;
  bool answer = false;

  cin >> W >> N;

  vector<int> weights(N);
  bool dp[800000] = {
      false,
  };

  for (int i = 0; i < N; i++) {
    cin >> weights[i];
  }

  for (int index = 0; index < N; index++) {
    for (int right = index + 1; right < N; right++) {
      int newWeight = weights[index] + weights[right];
      if (newWeight > W) continue;

      if (dp[W - newWeight]) {
        answer = true;
      }
    }
    for (int left = 0; left < index; left++) {
      int newWeight = weights[left] + weights[index];
      if (newWeight < W) {
        dp[newWeight] = true;
      }
    }
  }

  if (answer) {
    cout << "YES\n";

  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}