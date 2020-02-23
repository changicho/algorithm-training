#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool primeCheck[1000001] = {
    false,
};

bool canDivide(string number, int p) {
  int ret = 0;

  for (int i = 0; number[i]; i++) {
    ret *= 10;
    ret += (number[i] - '0');
    ret %= p;
  }

  return ret == 0;
}

void solution() {
  string P;
  int K, answer = -1;
  vector<int> primes;
  cin >> P >> K;

  for (int i = 2; i < K; i++) {
    if (i != 2 && i % 2 == 0) continue;
    if (primeCheck[i]) continue;

    primes.push_back(i);

    int k = i * 2;

    while (k < K) {
      primeCheck[k] = 1;
      k += i;
    }
  }

  for (int prime : primes) {
    if (canDivide(P, prime)) {
      answer = prime;
      break;
    }
  }

  if (answer == -1) {
    cout << "GOOD\n";
    return;
  }
  cout << "BAD " << answer << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}