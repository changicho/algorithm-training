#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 500000
#define MAX_LEVEL 16

using namespace std;

bool visited[MAX + 1];
int depths[MAX + 1];
int parents[MAX + 1][MAX_LEVEL + 1];
vector<vector<int> > graph;

void recursive(int current, int depth) {
  visited[current] = true;
  depths[current] = depth;

  for (int next : graph[current]) {
    if (visited[next]) continue;

    parents[next][0] = current;
    recursive(next, depth + 1);
  }
}

int lowestCommonAncestor(int first, int second) {
  // 첫번째가 자식 노드 높이를 더 낮도록 설정
  if (depths[first] > depths[second]) {
    swap(first, second);
  }

  // 높이를 맞춰줌
  for (int level = MAX_LEVEL; level >= 0; level--) {
    if (depths[second] - depths[first] >= (1 << level)) {
      second = parents[second][level];
    }
  }

  if (first == second) {
    return first;
  }
  for (int level = MAX_LEVEL; level >= 0; level--) {
    if (parents[first][level] != parents[second][level]) {
      first = parents[first][level];
      second = parents[second][level];
    }
  }

  return parents[first][0];
}

void solution() {
  int N, M;
  cin >> N;

  graph.resize(N + 1);

  int nodeA, nodeB;
  for (int i = 0; i < N - 1; i++) {
    cin >> nodeA >> nodeB;

    graph[nodeA].push_back(nodeB);
    graph[nodeB].push_back(nodeA);
  }

  recursive(1, 0);

  for (int level = 1; level <= MAX_LEVEL; level++) {
    for (int node = 1; node <= N; node++) {
      int parent = parents[node][level - 1];
      parents[node][level] = parents[parent][level - 1];
    }
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> nodeA >> nodeB;

    cout << lowestCommonAncestor(nodeA, nodeB) << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}