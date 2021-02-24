#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  vector<int> cards(N + 1);
  vector<int> sums(N + 1, 0);

  int dp[1001][1001] = {
      0,
  };

  for (int i = 1; i <= N; i++) {
    cin >> cards[i];
    sums[i] = sums[i - 1] + cards[i];
  }

  for (int index = 1; index <= N; index++) {
    dp[index][index] = cards[index];
  }

  for (int size = 1; size <= N; size++) {
    for (int index = 1; index <= N - size; index++) {
      int start = index, end = index + size;
      int sum = sums[end] - sums[start - 1];

      dp[start][end] = max(sum - dp[start + 1][end], sum - dp[start][end - 1]);
    }
  }

  cout << dp[1][N] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    solution();
  }
  return 0;
}