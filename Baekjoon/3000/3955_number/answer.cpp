#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long gcd(int a, int b) {
  if (a < b) swap(a, b);
  while (b != 0) {
    long long temp = a % b;
    a = b;
    b = temp;
  }
  return a < 0 ? -a : a;
}

struct extended {
  long long s, t, r;
};

extended extended_gcd(long long a, long long b) {
  long long old_s = 1, old_t = 0, old_r = a;
  long long new_s = 0, new_t = 1, new_r = b;

  while (new_r != 1) {
    long long q = old_r / new_r;
    long long temp;

    // update new, old value;
    temp = old_r;
    old_r = new_r;
    new_r = temp - new_r * q;

    temp = old_s;
    old_s = new_s;
    new_s = temp - new_s * q;

    temp = old_t;
    old_t = new_t;
    new_t = temp - new_t * q;
  }

  return extended{new_s, new_t, new_r};
}

void solution() {
  int T;
  long long K, C;

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> K >> C;

    if (C == 1) {
      if (K + 1 > 1e9)
        cout << "IMPOSSIBLE\n";
      else
        cout << K + 1 << "\n";
      continue;
    }
    if (K == 1) {
      cout << "1\n";
      continue;
    }
    if (gcd(K, C) != 1) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    extended result = extended_gcd(K, C);

    long long answer = result.t;
    while (answer < 0) answer += K;

    if (answer > 1e9)
      cout << "IMPOSSIBLE\n";
    else
      cout << answer << "\n";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}
