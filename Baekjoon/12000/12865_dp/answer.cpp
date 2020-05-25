#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct load {
  int W, V;
};

int dp[101][100001];
vector<load> loads;

void solution() {
  int N, W;
  int answer;

  cin >> N >> W;

  loads.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> loads[i].W >> loads[i].V;
  }

  for (int n = 1; n < N + 1; n++) {
    for (int w = 1; w < W + 1; w++) {
      if (loads[n - 1].W <= w) {
        dp[n][w] =
            max(loads[n - 1].V + dp[n - 1][w - loads[n - 1].W], dp[n - 1][w]);
      } else {
        dp[n][w] = dp[n - 1][w];
      }
    }
  }

  answer = dp[N][W];
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}