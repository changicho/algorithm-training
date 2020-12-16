#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int memoization[50001] = {
      0,
  };
  vector<int> sqrt_numbers;
  int N;
  cin >> N;

  for (int i = 1; i < sqrt(N) + 1; i++) {
    memoization[i * 1] = 1;
    sqrt_numbers.push_back(i * i);
  }

  for (int cur = 2; cur <= N; cur++) {
    int count = memoization[cur - 1];

    for (int number : sqrt_numbers) {
      if (number > cur) break;

      count = min(count, memoization[cur - number]);
    }

    memoization[cur] = count + 1;
  }

  cout << memoization[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}