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

int solution(int n, int m, vector<int> a, vector<int> b) {
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    graph[a[i]].push_back(b[i]);
  }

  queue<int> q;
  unordered_set<int> visited;

  q.push(1);
  visited.insert(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : graph[cur]) {
      if (next == -1) continue;
      if (visited.count(next) > 0) continue;
      visited.insert(next);
      q.push(next);
    }
  }

  return visited.size();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<int> A(M), B(M);

  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
  }

  auto answer = solution(N, M, A, B);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}