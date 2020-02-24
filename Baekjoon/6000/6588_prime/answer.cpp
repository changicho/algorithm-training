#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool primeCheck[1000001] = {
    false,
};
vector<int> primes;

void solution() {
  int N;

  for (int i = 2; i < 1000001; i++) {
    if (i != 2 && i % 2 == 0) continue;
    if (primeCheck[i]) continue;

    primes.push_back(i);

    int next = i * 2;

    while (next < 1000001) {
      primeCheck[next] = 1;
      next += i;
    }
  }

  while (cin >> N) {
    if (N == 0) {
      break;
    }

    bool isAnswer = 0;

    for (int prime : primes) {
      if (prime > N) {
        break;
      }
      if (!primeCheck[N - prime]) {
        isAnswer = 1;
        cout << N << " = " << prime << " + " << N - prime << "\n";
        break;
      }
    }

    if (!isAnswer) {
      cout << "Goldbach's conjecture is wrong.\n";
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