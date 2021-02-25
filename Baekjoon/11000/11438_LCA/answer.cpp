#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int depths[100001];
// it means the parent of current index;
int parents[100001][31];

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
  for (int level = 30; level >= 0; level--) {
    if (depths[second] - depths[first] >= (1 << level)) {
      second = parents[second][level];
    }
  }

  if (first == second) {
    return first;
  }
  for (int level = 30; level >= 0; level--) {
    if (parents[first][level] != parents[second][level]) {
      first = parents[first][level];
      second = parents[second][level];
    }
  }

  return parents[first][0];
}

void solution() {
  int N, M;
  int max_V = 0;

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int parent, child;
    cin >> parent >> child;

    graph[parent].push_back(child);
    graph[child].push_back(parent);
  }

  recursive(1, 0);  // 루트노드, 0
  for (int level = 1; level <= 30; level++) {
    for (int node = 1; node <= N; node++) {
      int parent = parents[node][level - 1];
      parents[node][level] = parents[parent][level - 1];
    }
  }

  cin >> M;

  while (M--) {
    int first, second;
    cin >> first >> second;

    int lca = lowestCommonAncestor(first, second);
    cout << lca << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}