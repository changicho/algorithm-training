#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int y, x;
  int answer = 1;

  cin >> x >> y;

  if (x > 0 && y > 0) {
    answer = 1;
  } else if (x < 0 && y > 0) {
    answer = 2;
  } else if (x < 0 && y < 0) {
    answer = 3;
  } else {
    answer = 4;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}