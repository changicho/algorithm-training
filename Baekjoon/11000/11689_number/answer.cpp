#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

long long myPow(long long value, long long square) {
  if (square == 0) return 1LL;
  if (square == 1) return value;
  if (square & 1) {  // square % 2 == 1
    return myPow(value, square - 1) * value;
  }

  long long root = myPow(value, square / 2);
  return root * root;
}

void solution() {
  long long N;

  cin >> N;

  long long answer = 1;
  for (long long number = 2; number * number <= N; number += 1) {
    long long count = 0;
    while (N % number == 0) {
      count += 1;
      N /= number;
    }
    if (count == 0) continue;

    answer *= (myPow(number, count) * (number - 1)) / number;
  }
  if (N != 1) {
    long long number = N, count = 1;
    answer *= (myPow(number, count) * (number - 1)) / number;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}