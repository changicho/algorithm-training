#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool primeCheck[10001];

void solution() {
  int S, E;
  int sum = 0;
  int minPrime = 10000;

  cin >> S >> E;

  for (int i = S; i <= E; i++) {
    if (!primeCheck[i]) {
      minPrime = min(i, minPrime);
      sum += i;
    }
  }

  if (sum == 0) {
    cout << "-1\n";
    return;
  }

  cout << sum << "\n" << minPrime << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  primeCheck[1] = true;

  for (int i = 2; i < 10000; i++) {
    if (primeCheck[i]) {
      continue;
    }

    int temp = i * 2;

    while (temp <= 10000) {
      primeCheck[temp] = true;
      temp += i;
    }
  }

  solution();

  return 0;
}