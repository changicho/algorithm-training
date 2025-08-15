#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;

  bool operator<(const Axis &b) const {
    if (y != b.y) return y < b.y;
    return x < b.x;
  }

  bool operator==(const Axis &b) const { return y == b.y && x == b.x; }
};

Axis getGradient(Axis &a, Axis &b) {
  int dy = b.y - a.y;
  int dx = b.x - a.x;

  // make dy positive
  if (dy < 0) {
    dy *= -1;
    dx *= -1;
  }

  if (dy == 0 && dx == 0) {
    return {0, 0};
  }
  if (dy == 0) {
    return {0, abs(dx)};
  }
  if (dx == 0) {
    return {abs(dy), 0};
  }
  return {dy, dx};
}

Axis divByGCD(Axis &p) {
  if (p.y == 0) {
    return {0, 1};
  }
  if (p.x == 0) {
    return {1, 0};
  }

  int g = gcd(abs(p.y), abs(p.x));
  return {p.y / g, p.x / g};
}

int count(vector<Axis> &points) {
  int size = points.size();
  sort(points.begin(), points.end());
  int ret = 0;

  int index = 0;
  while (index < size) {
    Axis target = points[index];

    int count = 0;
    while (index < size && points[index] == target) {
      count++;
      index++;
    }

    ret += (count - 1) * count / 2;
  }
  return ret;
}

auto solution(int size, vector<Axis> &points) {
  long long answer = 0;

  vector<Axis> originalGradients;
  vector<Axis> normalizedGradients;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      Axis gradient = getGradient(points[i], points[j]);

      originalGradients.push_back(gradient);
      normalizedGradients.push_back(divByGCD(gradient));
    }
  }

  return count(normalizedGradients) - count(originalGradients) / 2;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Axis> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i].y >> P[i].x;
  }

  auto answer = solution(N, P);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}