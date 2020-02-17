#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }

  // return abs
  if (a < 0) {
    return -a;
  }
  return a;
}

void solution() {
  int a, b, c, d;

  cin >> a >> b >> c >> d;

  int A = a * d + b * c;
  int B = b * d;
  int gcd_val;

  // make A is bigger than B
  if (A < B) {
    gcd_val = gcd(B, A);
  } else {
    gcd_val = gcd(A, B);
  }

  cout << A / gcd_val << " " << B / gcd_val << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}