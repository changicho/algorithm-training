#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void recursive(int node, int parent, vector<vector<int>>& graph,
               vector<bool>& visited, int& nodeCount) {
  visited[node] = true;
  nodeCount++;

  for (int& next : graph[node]) {
    if (next == parent) continue;

    if (visited[next]) continue;

    recursive(next, node, graph, visited, nodeCount);
  }
}

long long solution(int n, vector<pair<int, int>> edges) {
  vector<vector<int>> graph(n + 1);
  vector<bool> visited(n + 1, false);

  for (auto& edge : edges) {
    graph[edge.first].push_back(edge.second);
    graph[edge.second].push_back(edge.first);
  }

  long long answer = 0;
  for (int node = 1; node <= n; node++) {
    if (visited[node]) continue;

    int nodeCount = 0;
    recursive(node, -1, graph, visited, nodeCount);

    answer += (long long)nodeCount * (nodeCount - 1) / 2;
  }

  answer -= edges.size();

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

  vector<pair<int, int>> AB(M);
  for (int i = 0; i < M; i++) {
    cin >> AB[i].first >> AB[i].second;
  }

  long long answer = solution(N, AB);

  cout << answer << endl;

  return 0;
}