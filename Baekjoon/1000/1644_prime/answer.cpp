#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool primeCheck[4000001] = {
    false,
};
vector<int> primes;

void solution() {
  int N;
  long long count = 0;

  cin >> N;

  for (int i = 2; i <= N; i++) {
    if (i != 2 && i % 2 == 0) continue;
    if (primeCheck[i]) continue;

    primes.push_back(i);

    int next = i * 2;

    while (next <= N) {
      primeCheck[next] = 1;
      next += i;
    }
  }

  for (int i = 0; i < primes.size(); i++) {
    int sum = 0;
    for (int j = i; j < primes.size(); j++) {
      sum += primes[j];
      if (sum == N) {
        count += 1;
        break;
      }
      if (sum > N) break;
    }
  }

  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}