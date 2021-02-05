#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M, from, to;
  bool dp[2000][2000] = {
      false,
  };
  cin >> N;

  vector<int> array(N);
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  dp[0][0] = true;
  for (int i = 1; i < N; i++) {
    dp[i][i] = true;
    dp[i - 1][i] = array[i - 1] == array[i];
  }

  for (int length = 2; length < N; length += 1) {
    for (int from = 0; from < N - length; from += 1) {
      int to = from + length;

      dp[from][to] = array[from] == array[to] && dp[from + 1][to - 1];
    }
  }

  cin >> M;
  while (M--) {
    cin >> from >> to;

    cout << dp[from - 1][to - 1] << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}