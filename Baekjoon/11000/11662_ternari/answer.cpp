#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  double y, x;
};

struct Person {
  Axis start, end;
};

Person minsu, gangho;

double calculateCost(double percentage) {
  Axis new_minsu, new_gangho;

  new_minsu.y = minsu.start.y + (minsu.end.y - minsu.start.y) * percentage / 100;
  new_minsu.x = minsu.start.x + (minsu.end.x - minsu.start.x) * percentage / 100;

  new_gangho.y = gangho.start.y + (gangho.end.y - gangho.start.y) * percentage / 100;
  new_gangho.x = gangho.start.x + (gangho.end.x - gangho.start.x) * percentage / 100;

  double y = (new_minsu.y - new_gangho.y) * (new_minsu.y - new_gangho.y);
  double x = (new_minsu.x - new_gangho.x) * (new_minsu.x - new_gangho.x);

  return sqrt(y + x);
}

void solution() {
  double answer;

  cin >> minsu.start.y >> minsu.start.x >> minsu.end.y >> minsu.end.x;
  cin >> gangho.start.y >> gangho.start.x >> gangho.end.y >> gangho.end.x;

  double low = 0;
  double high = 100;

  while (high - low >= 1e-6) {
    double left = (2 * low + high) / 3;
    double right = (low + 2 * high) / 3;

    double leftCost = calculateCost(left);
    double rightCost = calculateCost(right);

    if (leftCost < rightCost) {
      high = right;
    } else {
      low = left;
    }
  }

  answer = calculateCost(low);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(7);

  solution();

  return 0;
}