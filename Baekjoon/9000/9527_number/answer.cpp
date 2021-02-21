#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long digit_count(long long number) {
  long long ret = 0;

  for (int i = 0; i < 55; i++) {
    ret += ((number + 1) >> (i + 1) << i);
    ret += max((long long)0, (number + 1) % (1LL << (i + 1)) - (1LL << i));
  }

  return ret;
}

void solution() {
  long long A, B;
  cin >> A >> B;

  long long answer = digit_count(B) - digit_count(A - 1);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}