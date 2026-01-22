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

void dfs(int node, int passed, int limit, const vector<vector<Edge>>& graph,
         long long cost, long long s, long long t, set<int>& answer) {
  if (passed == limit) {
    if (s <= cost && cost <= t) {
      answer.insert(node);
    }
    return;
  }

  for (const Edge& e : graph[node]) {
    if (cost + e.cost > t) {
      continue;
    }

    dfs(e.to, passed + 1, limit, graph, cost + e.cost, s, t, answer);
  }
}

vector<int> solution(int n, int size, int limit, long long s, long long t,
                     vector<Edge>& edges) {
  vector<int> answer;
  set<int> answerSet;

  vector<vector<Edge>> graph(n + 1);
  for (Edge& e : edges) {
    graph[e.from].push_back(e);
  }

  dfs(1, 0, limit, graph, 0, s, t, answerSet);

  for (int node : answerSet) {
    answer.push_back(node);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M, L;
  cin >> N >> M >> L;
  long long S, T;
  cin >> S >> T;

  vector<Edge> edges(M);
  for (int i = 0; i < M; i++) {
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
  }

  auto answer = solution(N, M, L, S, T, edges);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}