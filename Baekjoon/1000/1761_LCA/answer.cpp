#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 40000

using namespace std;

struct Node {
  int to, weight;
};

bool visited[MAX + 1];
int depths[MAX + 1];
int distArr[MAX + 1];
int parents[MAX + 1][20];

vector<vector<Node>> graph;

void recursive(Node node, int dist) {
  visited[node.to] = true;
  depths[node.to] = node.weight;
  distArr[node.to] = dist;

  for (Node u : graph[node.to]) {
    if (visited[u.to]) continue;

    recursive({u.to, node.weight + 1}, dist + u.weight);
    parents[u.to][0] = node.to;
  }
}

int lowestCommonAncestor(int x, int y) {
  if (depths[x] > depths[y]) swap(x, y);

  // 높이를 맞춰줌
  for (int i = 19; i >= 0; i--) {
    if (depths[y] - depths[x] >= (1 << i)) {
      y = parents[y][i];
    }
  }

  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (parents[x][i] != parents[y][i]) {
      x = parents[x][i];
      y = parents[y][i];
    }
  }

  return parents[x][0];
}

void solution() {
  int N, M;
  cin >> N;

  graph.resize(N + 1);

  for (int i = 0; i < N - 1; i++) {
    int parent, child, weight;
    cin >> parent >> child >> weight;

    graph[parent].push_back({child, weight});
    graph[child].push_back({parent, weight});
  }

  recursive({1, 0}, 0);

  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= N; i++)
      parents[i][j] = parents[parents[i][j - 1]][j - 1];
  }

  cin >> M;

  while (M--) {
    int to, weight;
    cin >> to >> weight;

    int lca = lowestCommonAncestor(to, weight);
    int answer = distArr[to] - distArr[lca] + distArr[weight] - distArr[lca];

    cout << answer << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}