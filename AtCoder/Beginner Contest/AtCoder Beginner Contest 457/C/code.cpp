#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

auto solution(int n, ll k, vector<vector<int>>& a, vector<int>& c) {
  for (int i = 0; i < n; i++) {
    vector<int>& line = a[i];

    if (k <= (ll)c[i] * line.size()) {
      return line[(k - 1) % line.size()];
    }

    k -= (ll)c[i] * line.size();
  }

  return -1;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  ll K;
  cin >> N >> K;

  vector<vector<int>> A(N);

  for (int i = 0; i < N; i++) {
    int L;
    cin >> L;

    A[i].resize(L);
    for (int j = 0; j < L; j++) {
      cin >> A[i][j];
    }
  }

  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }

  auto answer = solution(N, K, A, C);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}