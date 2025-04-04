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

int solution(int n, int m, vector<pair<int, int>> &edges) {
  vector<int> parents(n + 1);
  for (int i = 1; i <= n; i++) {
    parents[i] = i;
  }

  function<int(int)> find = [&](int x) {
    if (parents[x] != x) {
      parents[x] = find(parents[x]);
    }
    return parents[x];
  };
  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
      return;
    }

    if (a > b) swap(a, b);

    parents[b] = a;
  };

  int answer = 0;
  for (auto &edge : edges) {
    int a = edge.first;
    int b = edge.second;

    if (find(a) == find(b)) {
      answer++;
      continue;
    }

    merge(a, b);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> edges(M);

  for (int i = 0; i < M; i++) {
    cin >> edges[i].first >> edges[i].second;
  }

  int answer = solution(N, M, edges);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}