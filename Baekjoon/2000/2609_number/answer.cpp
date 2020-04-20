#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
  int tmp, n;

  if (a < b) {
    swap(a, b);
  }

  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}

void solution() {
  long long A, B;
  cin >> A >> B;
  long long GCD, LCM;

  GCD = gcd(A, B);
  LCM = A / GCD * B;

  cout << GCD << "\n" << LCM << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}