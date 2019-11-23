#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

long long int memoization[1000001];

long long my_pow(int first, int second) {
  long long power = 1;

  while (second != 0) {
    if (second & 1) {
      power = (power * first) % MOD;
    }
    first = (first * first) % MOD;

    second >>= 1;
  }

  return power;
}

void setMemo() {
  memoization[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    memoization[i] = (memoization[i - 1] + my_pow(i, i)) % MOD;
  }
}

void solution(int test_case) {
  int answer;
  int N;
  cin >> N;

  cout << "#" << test_case << " " << memoization[N] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  setMemo();

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}