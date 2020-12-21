#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }

  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

void solution() {
  int M, N, x, y;
  int year = -1;

  cin >> M >> N >> x >> y;

  int limit = lcm(M, N);

  for (int i = 0; x + i * M <= limit; i++) {
    int cnt_y = (x + i * M) % N;

    if (y == cnt_y || (N == y && cnt_y == 0)) {
      year = x + i * M;
      break;
    }
  }

  // for (int cur_year = x; cur_year <= limit; cur_year += M) {
  //   int count_y = cur_year % N;

  //   if (y == count_y || (N == y && count_y == 0)) {
  //     year = cur_year;
  //     break;
  //   }
  // }

  cout << year << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    solution();
  }

  return 0;
}