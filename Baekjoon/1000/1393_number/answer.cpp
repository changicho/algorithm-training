#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int getGcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;

  return getGcd(b, a % b);
}

int getLength(Axis a, Axis b) {
  return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

void solution() {
  Axis destination, start, diff, answer;

  cin >> destination.x >> destination.y;
  cin >> start.x >> start.y;
  cin >> diff.x >> diff.y;

  answer = start;

  int gcd = getGcd(abs(diff.x), abs(diff.y));

  if (gcd != 0) {
    diff.x /= gcd;
    diff.y /= gcd;
  }

  int length = getLength(destination, start);

  for (int i = 0; i < 200; i++) {
    start.x += diff.x;
    start.y += diff.y;

    int newLength = getLength(destination, start);

    if (newLength < length) {
      length = newLength;
      answer = start;
    }
  }

  cout << answer.x << " " << answer.y << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}