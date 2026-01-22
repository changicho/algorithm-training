#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long solution(int size, int k, long long x, vector<long long>& liquids) {
  sort(liquids.begin(), liquids.end());

  long long sakeSum = 0;
  for (int choosen = 1; choosen <= size; choosen++) {
    int maybeSake = max(0, k - (size - choosen));
    if (maybeSake == 0) continue;

    sakeSum += liquids[size - choosen];

    if (sakeSum >= x) {
      return choosen;
    }
  }

  return -1;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, K;
  long long X;
  cin >> N >> K >> X;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, K, X, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}