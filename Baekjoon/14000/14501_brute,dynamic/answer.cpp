#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct info {
  int T, P;
};

int dp[17];

void solution() {
  int N;
  int answer = 0;

  cin >> N;
  vector<info> infos(N);

  for (int i = 0; i < N; i++) {
    cin >> infos[i].T >> infos[i].P;
  }

  for (int i = 0; i < N; i++) {
    if (i + infos[i].T <= N) {
      dp[i + infos[i].T] = max(dp[i + infos[i].T], dp[i] + infos[i].P);
      answer = max(answer, dp[i + infos[i].T]);
    }

    dp[i + 1] = max(dp[i + 1], dp[i]);
    answer = max(answer, dp[i + 1]);
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