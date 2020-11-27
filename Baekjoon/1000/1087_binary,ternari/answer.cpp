#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  double y, x;
};

struct Mouse {
  Axis axis, move;
};

vector<Mouse> mice;

double calculateCost(double time) {
  double start_x = 1e9, start_y = 1e9, end_x = -1e9, end_y = -1e9;

  for (Mouse mouse : mice) {
    start_x = min(start_x, mouse.axis.x + mouse.move.x * time);
    start_y = min(start_y, mouse.axis.y + mouse.move.y * time);
    end_x = max(end_x, mouse.axis.x + mouse.move.x * time);
    end_y = max(end_y, mouse.axis.y + mouse.move.y * time);
  }

  return max(end_x - start_x, end_y - start_y);
}

void solution() {
  int N;
  double answer;

  cin >> N;

  for (int i = 0; i < N; i++) {
    Mouse mouse;
    cin >> mouse.axis.y >> mouse.axis.x >> mouse.move.y >> mouse.move.x;

    mice.push_back(mouse);
  }

  double low = 0, high = 1e5;

  for (int i = 0; i < 200 && low < high; i++) {
    double left = (2 * low + high) / 3;
    double right = (low + 2 * high) / 3;

    double costL = calculateCost(left);
    double costR = calculateCost(right);

    if (costL < costR) {
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
  cout.precision(11);

  solution();

  return 0;
}