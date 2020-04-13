#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct house {
  int color[3];
};

int dp[1001][3];

void solution() {
  int N;
  int answer = 0;
  cin >> N;

  vector<house> h;

  for (int i = 0; i < N; i++) {
    house temp;
    cin >> temp.color[0] >> temp.color[1] >> temp.color[2];

    h.push_back(temp);
  }

  dp[0][0] = h[0].color[0];
  dp[0][1] = h[0].color[1];
  dp[0][2] = h[0].color[2];

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = dp[i - 1][(j + 1) % 3] + h[i].color[j];

      for (int k = 0; k < 3; k++) {
        if (j == k) continue;

        dp[i][j] = min(dp[i][j], dp[i - 1][k] + h[i].color[j]);
      }
    }
  }

  answer = dp[N - 1][0];
  for (int i = 0; i < 3; i++) {
    answer = min(answer, dp[N - 1][i]);
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