#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int combi(int n, int k) {
  if (k == 0 || n == k) return 1;

  // case_choose + case_not_choose
  return combi(n - 1, k - 1) + combi(n - 1, k);
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