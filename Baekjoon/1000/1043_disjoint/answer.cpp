#include <algorithm>
#include <iostream>
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
  int size, target;
  int N, M;
  int answer = 0;

  cin >> N >> M;

  DisjointSet ds(N + 1);
  cin >> size;

  vector<int> knows(size);
  for (int i = 0; i < size; i++) {
    cin >> knows[i];
    ds.merge(knows[i], knows.front());
  }

  vector<vector<int> > parties(M);
  for (vector<int> &party : parties) {
    cin >> size;

    party.resize(size);
    for (int j = 0; j < size; j++) {
      cin >> party[j];

      ds.merge(party[j], party.front());
    }
  }

  for (vector<int> party : parties) {
    if (knows.empty() || !ds.isLinked(party.front(), knows.front())) {
      answer += 1;
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}