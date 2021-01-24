#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Edge {
  int from, to, weight;

  bool const operator<(const Edge &b) const {
    return weight < b.weight;
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
  int V, E;
  long long sum = 0;

  cin >> V >> E;

  vector<Edge> edges;

  UnionFind unionfind(V + 1);

  int from, to, cost;
  for (int l = 0; l < E; l++) {
    cin >> from >> to >> cost;
    edges.push_back({from, to, cost});
  }

  sort(edges.begin(), edges.end());

  for (Edge l : edges) {
    if (unionfind.findParent(l.from) == unionfind.findParent(l.to)) continue;

    unionfind.merge(l.from, l.to);
    sum += l.weight;
  }

  cout << sum << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}