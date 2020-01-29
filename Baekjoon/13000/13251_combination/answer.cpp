#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  double answer = 0;

  int M, K, N = 0;
  vector<int> pebbles;

  cin >> M;

  for (int i = 0; i < M; i++) {
    int pebble;
    cin >> pebble;
    pebbles.push_back(pebble);
    N += pebble;
  }

  cin >> K;

  for (int p : pebbles) {
    if (p < K) continue;

    double temp = 1;

    for (int i = 0; i < K; i++) {
      temp *= (double)(p - i) / (double)(N - i);
    }

    answer += temp;
  }

  cout << fixed;
  cout.precision(12);
  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}