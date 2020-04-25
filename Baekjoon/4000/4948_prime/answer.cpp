#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 250000

using namespace std;

bool notPrime[MAX];

void calcul() {
  notPrime[1] = true;

  for (int i = 2; i < MAX; i++) {
    int temp = i + i;

    while (temp < MAX) {
      notPrime[temp] = true;
      temp += i;
    }
  }
}

void solution() {
  int N;

  while (cin >> N) {
    if (N == 0) break;
    int count = 0;

    for (int i = N + 1; i <= N + N; i++) {
      if (!notPrime[i]) {
        count += 1;
      }
    }

    cout << count << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  calcul();
  solution();

  return 0;
}