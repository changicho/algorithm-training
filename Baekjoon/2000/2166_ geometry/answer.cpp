#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  double x, y;
};

vector<Axis> points;

double ccw(Axis a, Axis b, Axis c) {
  return ((a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x));
}

void solution() {
  int N;
  double answer = 0;

  cin >> N;
  points.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> points[i].x >> points[i].y;
  }

  Axis start = points.front();

  for (int i = 2; i < N; i++) {
    double ccw_answer = ccw(start, points[i - 1], points[i]) / 2;
    answer += ccw_answer;
  }
  answer = abs(answer);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(1);

  solution();

  return 0;
}