#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ladder[3];
int ladder_max[2][3];
int ladder_min[2][3];

void solution() {
  int N;

  cin >> N;

  for (int j = 0; j < 3; j++) {
    cin >> ladder[j];
  }

  for (int j = 0; j < 3; j++) {
    ladder_max[0][j] = ladder[j];
    ladder_min[0][j] = ladder[j];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> ladder[j];
    }

    // max
    for (int j = 0; j < 3; j++) {
      ladder_max[1][j] = ladder_max[0][j] + ladder[j];

      for (int k = max(0, j - 1); k <= min(2, j + 1); k++) {
        int new_max = ladder_max[0][k] + ladder[j];
        if (new_max > ladder_max[1][j]) ladder_max[1][j] = new_max;
      }
    }

    // min
    for (int j = 0; j < 3; j++) {
      ladder_min[1][j] = ladder_min[0][j] + ladder[j];

      for (int k = max(0, j - 1); k <= min(2, j + 1); k++) {
        int new_min = ladder_min[0][k] + ladder[j];
        if (new_min < ladder_min[1][j]) ladder_min[1][j] = new_min;
      }
    }

    // 이전 계산 결과 갱신
    for (int j = 0; j < 3; j++) {
      ladder_max[0][j] = ladder_max[1][j];
      ladder_min[0][j] = ladder_min[1][j];
    }
  }

  int answer_max = ladder_max[0][0];
  int answer_min = ladder_max[0][0];

  for (int i = 0; i < 3; i++) {
    answer_max = max(answer_max, ladder_max[0][i]);
    answer_min = min(answer_min, ladder_min[0][i]);
  }

  cout << answer_max << " " << answer_min << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}