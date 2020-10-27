#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  vector<string> lamps;
  int answer = 0;
  int N, M, K;

  cin >> N >> M;

  lamps.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> lamps[i];
  }

  cin >> K;

  for (int y = 0; y < N; y++) {
    int zeroCount = 0;

    for (char c : lamps[y]) {
      if (c == '0') zeroCount++;
    }

    int sum = 0;

    if (zeroCount <= K && zeroCount % 2 == K % 2) {
      for (int temp_y = 0; temp_y < N; temp_y++) {
        if (lamps[y] == lamps[temp_y]) {
          sum++;
        }
      }
    }

    answer = max(sum, answer);
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