#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

void solution() {
  double answer = 1e10;
  int N;
  cin >> N;

  vector<Axis> points(N);
  vector<bool> checks(N, false);

  for (int i = 0; i < N / 2; i++) {
    checks[i] = true;
  }
  sort(checks.begin(), checks.end());

  for (int i = 0; i < N; i++) {
    cin >> points[i].y >> points[i].x;
  }

  do {
    double sumX = 0, sumY = 0;

    for (int i = 0; i < N; i++) {
      if (checks[i]) {
        sumX += points[i].x;
        sumY += points[i].y;
      } else {
        sumX -= points[i].x;
        sumY -= points[i].y;
      }
    }

    double curAnswer = sqrt(sumY * sumY + sumX * sumX);
    answer = min(answer, curAnswer);
  } while (next_permutation(checks.begin(), checks.end()));

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(7);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    solution();
  }

  return 0;
}