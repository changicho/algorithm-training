#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct matrix {
  int r, c;
};

// i번째 행렬부터 j번째 행렬까지 행렬곱 했을 때 필요한 최소 연산 횟수
int dp[501][501] = {
    0,
};
matrix m[501];

void solution() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> m[i].r >> m[i].c;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      int f = j;
      int t = j + i;
      if (t > N) break;

      int currentValue = 1 << 30;
      for (int k = f + 1; k <= t; k++) {
        int temp = dp[f][k - 1] + dp[k][t] + m[f].r * m[k].r * m[t].c;
        if (temp < currentValue) currentValue = temp;
      }
      dp[f][t] = currentValue;
    }
  }

  cout << dp[1][N] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}