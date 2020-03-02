#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// first : n, second : k;
int memo[1000][1000];
int diff = 10007;

int combi(int n, int k) {
  if (memo[n][k] != 0) {
    return memo[n][k];
  }

  if (k == 0 || n == k) {
    memo[n][k] = 1;
    return 1;
  }

  // case_choose + case_not_choose
  int sum = combi(n - 1, k - 1) + combi(n - 1, k);
  sum %= diff;
  memo[n][k] = sum;

  return sum;
}

void solution() {
  int n, k;

  cin >> n >> k;

  cout << combi(n, k) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}