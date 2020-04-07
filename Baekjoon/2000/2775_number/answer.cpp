#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[15][15] = {
    0,
};

void solution() {
  int K, N;

  cin >> K >> N;

  cout << map[K][N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int i = 0; i < 15; i++) {
    map[0][i] = i;
  }

  for (int j = 1; j < 15; j++) {
    for (int i = 1; i < 15; i++) {
      map[j][i] = map[j][i - 1] + map[j - 1][i];
    }
  }

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}