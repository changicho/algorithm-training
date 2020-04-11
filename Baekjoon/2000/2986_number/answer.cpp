#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, diff = 1;
  cin >> N;

  int limit = sqrt(N) + 1;

  for (int i = 2; i <= limit; i++) {
    if (N % i == 0) {
      diff = N / i;
      break;
    }
  }
  cout << N - diff << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}