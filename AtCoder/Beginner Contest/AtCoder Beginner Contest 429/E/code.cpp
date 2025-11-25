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

struct Status {
  int from;
  int node;
  int step;
};

auto solution(int n, int m, vector<Edge>& edges, string& status) {
  // 1st closest safe cost, 2nd closest safe cost
  vector<vector<int>> minCosts(n);
  vector<unordered_set<int>> visited(n);

  vector<vector<int>> graph(n);

  for (Edge& e : edges) {
    int a = e.from - 1, b = e.to - 1;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // BFS step
  queue<Status> q;
  for (int i = 0; i < n; i++) {
    if (status[i] == 'S') {
      q.push({i, i, 0});
      minCosts[i].push_back(0);
      visited[i].insert(i);
    }
  }

  int step = 0;
  while (!q.empty()) {
    int size = q.size();
    step++;

    while (size--) {
      Status cur = q.front();
      q.pop();

      for (int& next : graph[cur.node]) {
        if (minCosts[next].size() == 2) continue;
        if (visited[next].count(cur.from)) continue;

        visited[next].insert(cur.from);
        minCosts[next].push_back(step);

        q.push({cur.from, next, step});
      }
    }
  }

  vector<long long> answer;
  for (int i = 0; i < n; i++) {
    if (status[i] == 'D') {
      long long cur = minCosts[i][0] + minCosts[i][1];
      answer.push_back(cur);
    }
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

  vector<Edge> edges(M);
  for (int i = 0; i < M; i++) {
    cin >> edges[i].from >> edges[i].to;
  }
  string S;
  cin >> S;

  auto answer = solution(N, M, edges, S);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}