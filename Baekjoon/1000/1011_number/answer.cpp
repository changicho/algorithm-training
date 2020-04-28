#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long x, y;

  cin >> x >> y;
  long long distance = y - x;
  long long answer = 0;
  long long sq = 1;

  while (sq * sq < distance) {
    sq += 1;
  }

  answer = (sq - 1) * 2 + 1;

  long long center = (sq * sq + (sq - 1) * (sq - 1)) / 2;
  if (distance <= center) {
    answer -= 1;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}