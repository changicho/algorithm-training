#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Point {
  int x, y;
  int xDiff, yDiff;

  bool operator<(const Point &B) const {
    // 벡터의 내적을 이용해 사이각을 구함
    if (1LL * (yDiff * B.xDiff) != 1LL * (xDiff * B.yDiff)) {
      return 1LL * (yDiff * B.xDiff) < 1LL * (xDiff * B.yDiff);
    }
    if (y != B.y) {
      return y < B.y;
    }
    return x < B.x;
  }
};

// 벡터의 내적을 이용해 사이각을 구함
inline long long getInnerProduct(Point &A, Point &B, Point &C) {
  return 1LL * ((A.x * B.y + B.x * C.y + C.x * A.y) - (B.x * A.y + C.x * B.y + A.x * C.y));
}

inline bool isCCW(Point &A, Point &B, Point &C) {
  return getInnerProduct(A, B, C) > 0;
}

void solution() {
  int N;
  cin >> N;

  vector<Point> points(N);

  for (int i = 0; i < N; i++) {
    cin >> points[i].x >> points[i].y;

    points[i].xDiff = points[i].yDiff = 0;
  }

  sort(points.begin(), points.end());
  // 첫번째 점(기준점)에 맞춰 기준과의 거리를 계산
  for (int i = 1; i < N; i++) {
    points[i].xDiff = points[i].x - points.front().x;
    points[i].yDiff = points[i].y - points.front().y;
  }
  sort(points.begin(), points.end());

  stack<int> s;

  s.push(0);
  s.push(1);

  int next = 2;

  while (next < N) {
    while (s.size() >= 2) {
      int first, second;
      second = s.top();
      s.pop();
      first = s.top();

      if (isCCW(points[first], points[second], points[next])) {
        s.push(second);
        break;
      }
    }

    s.push(next);
    next += 1;
  }

  cout << s.size() << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}