#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 100000
#define LIMIT 1000000

using namespace std;

struct Node {
  int to, cost;
};

vector<vector<Node> > graph;
bool visited[MAX + 1];
int depths[MAX + 1];
int parents[MAX + 1][21];
int max_distances[MAX + 1][21];
int min_distances[MAX + 1][21];

void recursive(int from, int depth) {
  visited[from] = true;
  depths[from] = depth;

  for (Node cur : graph[from]) {
    if (visited[cur.to]) continue;

    recursive(cur.to, depth + 1);

    parents[cur.to][0] = from;
    min_distances[cur.to][0] = cur.cost;
    max_distances[cur.to][0] = cur.cost;
  }
}

void LCA_init(int N) {
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= N; i++) {
      parents[i][j] = parents[parents[i][j - 1]][j - 1];
      min_distances[i][j] = min(min_distances[i][j - 1], min_distances[parents[i][j - 1]][j - 1]);
      max_distances[i][j] = max(max_distances[i][j - 1], max_distances[parents[i][j - 1]][j - 1]);
    }
  }
}

pair<int, int> LCA_query(int x, int y) {
  int answer_min = LIMIT;
  int answer_max = -LIMIT;

  if (depths[x] > depths[y]) swap(x, y);

  for (int i = 20; i >= 0; i--) {
    if (depths[y] - depths[x] >= (1 << i)) {
      answer_min = min(answer_min, min_distances[y][i]);
      answer_max = max(answer_max, max_distances[y][i]);

      y = parents[y][i];
    }
  }

  if (x == y) return {answer_min, answer_max};

  for (int i = 20; i >= 0; i--) {
    if (parents[x][i] != parents[y][i]) {
      answer_min = min(answer_min, min(min_distances[x][i], min_distances[y][i]));
      answer_max = max(answer_max, max(max_distances[x][i], max_distances[y][i]));

      x = parents[x][i];
      y = parents[y][i];
    }
  }

  answer_min = min(answer_min, min(min_distances[x][0], min_distances[y][0]));
  answer_max = max(answer_max, max(max_distances[x][0], max_distances[y][0]));

  return {answer_min, answer_max};
}

void solution() {
  int N, K;

  cin >> N;
  graph.resize(N + 1);

  for (int i = 0; i < N - 1; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  recursive(1, 0);
  LCA_init(N);

  cin >> K;

  for (int i = 0; i < K; i++) {
    int from, to;
    cin >> from >> to;

    pair<int, int> lca = LCA_query(from, to);
    cout << lca.first << " " << lca.second << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}