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

struct Edge {
  int from, to;
};

bool solution(int n, int m, vector<Edge> &edges) {
  if (m != n) return false;

  vector<int> inDegrees(n, 0);

  for (auto &edge : edges) {
    inDegrees[edge.to - 1]++;
    inDegrees[edge.from - 1]++;
  }

  for (int i = 0; i < n; i++) {
    if (inDegrees[i] != 2) {
      return false;
    }
  }

  // check graph count
  vector<int> parents(n);
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }
  int group = n;
  function<int(int)> find = [&](int x) {
    if (parents[x] == x) {
      return x;
    }
    return parents[x] = find(parents[x]);
  };

  function<void(int, int)> merge = [&](int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (x > y) {
      swap(x, y);
    }
    group--;
    parents[y] = x;
  };

  for (auto &edge : edges) {
    int x = edge.from - 1;
    int y = edge.to - 1;
    merge(x, y);
  }

  if (group != 1) return false;

  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;
  vector<Edge> edges(M);

  for (int i = 0; i < M; i++) {
    cin >> edges[i].from >> edges[i].to;
  }

  bool answer = solution(N, M, edges);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}