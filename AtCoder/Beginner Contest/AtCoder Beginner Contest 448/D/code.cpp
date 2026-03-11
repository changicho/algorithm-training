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

struct Edge {
  int from, to;
};

vector<bool> solution(int size, vector<int>& nums, vector<Edge>& edges) {
  vector<bool> answer(size);

  vector<vector<int>> graph(size + 1);
  for (Edge& e : edges) {
    graph[e.from].push_back(e.to);
    graph[e.to].push_back(e.from);
  }

  unordered_set<int> visited;
  multiset<int> values;
  unordered_map<int, int> counts;

  function<void(int, bool)> dfs = [&](int node, bool hasSame) {
    visited.insert(node);

    int val = nums[node - 1];
    counts[val]++;

    if (counts[val] >= 2) {
      hasSame |= true;
    }
    answer[node - 1] = hasSame;

    for (int next : graph[node]) {
      if (visited.count(next)) continue;
      dfs(next, hasSame || counts[val] >= 2);
    }

    counts[val]--;
  };

  dfs(1, false);

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

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<Edge> edges(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> edges[i].from >> edges[i].to;
  }

  auto answer = solution(N, A, edges);

  // cout << answer << endl;
  for (bool line : answer) {
    cout << (line ? "Yes" : "No") << endl;
    // cout << line << "\n";
  }
  cout << endl;

  return 0;
}