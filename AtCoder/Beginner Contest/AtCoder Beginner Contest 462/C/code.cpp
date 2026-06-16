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

ll solution(int size, vector<int>& x, vector<int>& y) {
  int answer = 0;

  vector<pair<int, int>> points;
  for (int i = 0; i < size; i++) {
    points.push_back({x[i], y[i]});
  }
  sort(points.begin(), points.end());

  set<int> s;
  s.insert(INT_MIN);
  s.insert(INT_MAX);
  for (int i = 0; i < size; i++) {
    int y = points[i].second;

    // find there are lower than y
    auto it = prev(s.lower_bound(y));

    if (*it == INT_MIN) answer++;

    s.insert(y);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> X(N), Y(N);

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  ll answer = solution(N, X, Y);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}