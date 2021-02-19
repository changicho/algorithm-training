#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct DisjointSet {
  vector<int> parents;
  vector<int> counts;

  DisjointSet(int size) {
    parents.resize(size);
    counts.resize(size);

    for (int i = 0; i < size; i++) {
      parents[i] = i;
      counts[i] = 1;
    }
  }

  int findNode(int node) {
    if (parents[node] == node) return node;

    return parents[node] = findNode(parents[node]);
  }

  bool isLinked(int nodeA, int nodeB) {
    return findNode(nodeA) == findNode(nodeB);
  }

  void merge(int nodeA, int nodeB) {
    if (nodeA > nodeB) swap(nodeA, nodeB);

    nodeA = findNode(nodeA);
    nodeB = findNode(nodeB);

    if (nodeA == nodeB) return;
    if (counts[nodeA] < counts[nodeB]) swap(nodeA, nodeB);

    parents[nodeB] = nodeA;
    if (counts[nodeA] == counts[nodeB]) counts[nodeB]++;
  }
};

void solution() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<int> costs(N + 1);
  DisjointSet ds(N + 1);

  for (int i = 1; i < N + 1; i++) {
    cin >> costs[i];
  }

  int from, to;
  for (int i = 0; i < M; i++) {
    cin >> from >> to;

    ds.merge(from, to);
  }

  map<int, int> costOfSet;

  for (int node = 1; node < N + 1; node++) {
    int parent = ds.findNode(node);

    if (costOfSet[parent] == 0) {
      costOfSet[parent] = costs[node];
    } else {
      costOfSet[parent] = min(costOfSet[parent], costs[node]);
    }
  }

  int answer = 0;
  for (pair<int, int> cur : costOfSet) {
    answer += cur.second;
  }

  if (answer > K) {
    cout << "Oh no\n";
  } else {
    cout << answer << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}