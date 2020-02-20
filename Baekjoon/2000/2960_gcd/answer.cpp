#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPrime[1001] = {
    false,
};

void solution() {
  int N, K, count = 0;

  cin >> N >> K;

  for (int i = 2; i <= N; i++) {
    int k = i;

    while (k <= N) {
      if (isPrime[k]) {
        k += i;
        continue;
      };

      count += 1;
      isPrime[k] = 1;

      if (count == K) {
        cout << k << "\n";
        return;
      }

      k += i;
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