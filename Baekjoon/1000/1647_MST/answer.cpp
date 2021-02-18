#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;

  bool const operator<(const Edge &b) const {
    return cost < b.cost;
  }
};

struct UnionFind {
  vector<int> cycleTable;

  UnionFind(int size) {
    cycleTable.resize(size + 1);

    for (int i = 1; i <= size; i++) {
      cycleTable[i] = i;
    }
  }

  int findParent(int index) {
    if (cycleTable[index] == index) {
      return index;
    } else {
      int p = findParent(cycleTable[index]);
      cycleTable[index] = p;

      return cycleTable[index];
    }
  }

  void merge(int a, int b) {
    int aRoot = findParent(a);
    int bRoot = findParent(b);

    if (a < b) swap(aRoot, bRoot);
    cycleTable[aRoot] = bRoot;
  }
};

void solution() {
  int N, M;
  cin >> N >> M;

  vector<int> costs;
  vector<Edge> edges;

  int from, to, cost;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;

    edges.push_back({from, to, cost});
    edges.push_back({to, from, cost});
  }

  UnionFind unionfind(N);

  sort(edges.begin(), edges.end());
  long long answer = 0;

  for (Edge l : edges) {
    if (unionfind.findParent(l.from) == unionfind.findParent(l.to)) continue;

    costs.push_back(l.cost);
    unionfind.merge(l.from, l.to);
    answer += l.cost;
  }

  sort(costs.begin(), costs.end());
  answer -= costs.back();

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}