#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long memo[31][31] = {
    0,
};

long long combination(int n, int k) {
  if (memo[n][k] != 0) {
    return memo[n][k];
  }

  if (k == 0 || n == k) {
    memo[n][k] = 1;
    return 1;
  }

  // case_choose + case_not_choose
  long long sum = combination(n - 1, k - 1) + combination(n - 1, k);
  memo[n][k] = sum;

  return sum;
}

void solution() {
  int N, M;

  cin >> N >> M;

  cout << combination(M, N) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solution();
  }

  return 0;
}