#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Rectangle {
  int x;
  int yStart, yEnd;
  bool isLeft;

  bool operator<(const Rectangle &b) const {
    if (x != b.x) {
      return x < b.x;
    }
    return !isLeft && b.isLeft;
  }
};

void solution() {
  int board[20001] = {
      0,
  };
  int N;
  cin >> N;

  vector<Rectangle> rectangles;

  for (int i = 0; i < N; i++) {
    double x, y, width, height;
    Rectangle rectangle;
    cin >> x >> y >> width >> height;

    x *= 10;
    y *= 10;
    width *= 10;
    height *= 10;

    rectangle = {(int)x, (int)y, (int)(y + height), true};
    rectangles.push_back(rectangle);

    rectangle = {(int)(x + width), (int)y, (int)(y + height), false};
    rectangles.push_back(rectangle);
  }

  sort(rectangles.begin(), rectangles.end());

  long long answer = 0;
  int currentX = 0;
  for (Rectangle rectangle : rectangles) {
    int count = 0;
    for (int y = 0; y <= 20000; y++) {
      if (board[y] > 0) {
        count++;
      }
    }

    answer += count * (rectangle.x - currentX);

    for (int y = rectangle.yStart + 1; y <= rectangle.yEnd; y++) {
      board[y] += rectangle.isLeft ? 1 : -1;
    }
    currentX = rectangle.x;
  }

  if (answer % 100 == 0) {
    cout << answer / 100 << "\n";
  } else {
    cout << answer / 100.0 << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(2);

  solution();

  return 0;
}