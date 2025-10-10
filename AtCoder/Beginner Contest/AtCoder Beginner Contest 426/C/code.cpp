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

auto solution(int n, int qSize, vector<pair<int, int>> &queries) {
  vector<int> os(n + 1);
  for (int i = 1; i <= n; i++) {
    os[i] = 1;
  }

  int minimum = 1;
  vector<int> answer;

  for (pair<int, int> &q : queries) {
    int x = q.first;
    int y = q.second;

    if (x < minimum) {
      answer.push_back(0);
      continue;
    }

    int count = 0;
    for (int i = minimum; i <= x; i++) {
      count += os[i];
      os[i] = 0;
    }

    os[y] += count;

    minimum = x + 1;
    answer.push_back(count);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<pair<int, int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i].first >> queries[i].second;
  }

  auto answer = solution(N, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}