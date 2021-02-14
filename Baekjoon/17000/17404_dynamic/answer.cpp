#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int make_index(int index, int diff) {
  return (index + diff + 3) % 3;
}

void solution() {
  int dp[1000][3] = {
      0,
  };
  int colors[1000][3] = {
      0,
  };
  int answer = 1000 * 1000 + 1;
  int N;
  cin >> N;

  for (int index = 0; index < N; index++) {
    for (int color = 0; color < 3; color++) {
      cin >> colors[index][color];
    }
  }

  for (int start_color = 0; start_color < 3; start_color++) {
    for (int color = 0; color < 3; color++) {
      dp[0][color] = start_color == color ? colors[0][color] : 1000 * 1000 + 1;
    }

    for (int index = 1; index < N; index++) {
      for (int color = 0; color < 3; color++) {
        int left_cost = dp[index - 1][make_index(color, +1)];
        int right_cost = dp[index - 1][make_index(color, -1)];

        dp[index][color] = min(left_cost, right_cost) + colors[index][color];
      }
    }
    for (int color = 0; color < 3; color++) {
      if (color == start_color) continue;
      answer = min(answer, dp[N - 1][color]);
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