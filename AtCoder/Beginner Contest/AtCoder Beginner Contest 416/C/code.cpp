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

string solution(int n, int k, int x, vector<string> &s) {
  vector<string> arr;

  function<void(int, string &)> dfs = [&](int idx, string &current) {
    if (idx == k) {
      arr.push_back(current);
      return;
    }

    for (int i = 0; i < n; i++) {
      string before = current;
      current += s[i];
      dfs(idx + 1, current);
      current = before;
    }
  };

  string current = "";
  dfs(0, current);

  sort(arr.begin(), arr.end());

  return arr[x - 1];
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, K, X;
  cin >> N >> K >> X;

  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  string answer = solution(N, K, X, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}