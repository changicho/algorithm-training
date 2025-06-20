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
  int from, to, cost;
};

int solution(int n, int size, vector<Edge> &edges) {
  vector<int> costs(n, INT_MAX);

  vector<vector<Edge>> graph(n);
  for (int i = 0; i < size; i++) {
    graph[edges[i].from].push_back(edges[i]);
  }

  queue<Edge> q;
  vector<vector<bool>> visited(n, vector<bool>(1024, false));
  q.push({0, 0, 0});
  costs[0] = 0;

  while (!q.empty()) {
    Edge cur = q.front();
    q.pop();

    if (visited[cur.to][cur.cost]) continue;
    visited[cur.to][cur.cost] = true;

    for (Edge &next : graph[cur.to]) {
      int newCost = cur.cost ^ next.cost;

      if (visited[next.to][newCost]) continue;

      costs[next.to] = min(costs[next.to], newCost);
      q.push({next.from, next.to, newCost});
    }
  }

  return costs[n - 1] == INT_MAX ? -1 : costs[n - 1];
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
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    edges[i].from--;
    edges[i].to--;
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