#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool primeCheck[10000001] = {
    0,
};

void solution() {
  int N;

  cin >> N;

  vector<int> primes;

  for (int i = 2; i <= N; i++) {
    if (i != 2 && i % 2 == 0) {
      continue;
    }

    if (primeCheck[i]) {
      continue;
    }
    primes.push_back(i);
    int k = i * 2;

    while (k <= N) {
      primeCheck[k] = 1;
      k += i;
    }
  }

  for (int i : primes) {
    while (N % i == 0) {
      cout << i << "\n";
      N /= i;

      if (N == 1) {
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}