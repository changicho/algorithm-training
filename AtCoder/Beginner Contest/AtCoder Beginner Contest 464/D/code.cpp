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

long long solution(int size, string& s, vector<int>& x, vector<int>& y) {
  // 0 : rainy
  // 1 : sunny
  long long before[2] = {
      0,
  };

  before[0] = (s[0] == 'R') ? 0 : -x[0];
  before[1] = (s[0] == 'S') ? 0 : -x[0];

  for (int i = 1; i < size; i++) {
    long long dp[2];
    dp[0] = max(before[1], before[0]);
    dp[1] = max(before[1], before[0] + y[i - 1]);

    bool isRainy = s[i] == 'R';

    if (isRainy) {
      dp[1] -= x[i];
    } else {
      dp[0] -= x[i];
    }

    swap(before, dp);
  }

  return max(before[0], before[1]);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int N;
    string S;
    cin >> N >> S;

    vector<int> X(N), Y(N - 1);
    for (int i = 0; i < N; i++) {
      cin >> X[i];
    }
    for (int i = 0; i < N - 1; i++) {
      cin >> Y[i];
    }

    auto answer = solution(N, S, X, Y);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}