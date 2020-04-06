#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int W, H, N;
  int count = 0;

  cin >> W >> H >> N;

  for (int h = 1; h <= H; h++) {
    for (int w = 1; w <= W; w++) {
      count += 1;

      if (count == N) {
        cout << w * 100 + h << "\n";

        return;
      }
    }
  }
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