#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(string &target, vector<vector<string>> &arr) {
  int size = target.size();

  vector<int> dp(size + 1, INT_MAX);
  dp[0] = 0;

  for (vector<string> &v : arr) {
    vector<int> dp2 = dp;

    for (string &word : v) {
      int len = word.size();

      for (int i = 0; i < size; i++) {
        if (i + len > size) break;
        if (dp[i] == INT_MAX) continue;

        if (target.substr(i, len) == word) {
          dp2[i + len] = min(dp2[i + len], dp[i] + 1);
        }
      }
    }

    dp = dp2;
  }

  // for (int i = 0; i <= size; i++) {
  //   cout << dp[i] << ' ';
  // }
  // cout << endl;

  if (dp.back() == INT_MAX) {
    return -1;
  }
  return dp.back();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string T;
  int N;

  cin >> T >> N;

  vector<vector<string>> A(N);
  for (int i = 0; i < N; i++) {
    int size;
    string S;

    cin >> size;
    while (size--) {
      cin >> S;
      A[i].push_back(S);
    }
  }

  int answer = solution(T, A);
  cout << answer << '\n';

  return 0;
}