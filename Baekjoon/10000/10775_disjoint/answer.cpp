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
  int G, P;
  cin >> G >> P;

  DisjointSet ds(G + 1);

  int answer = 0;

  vector<int> goals(P);
  int goal;
  for (int i = 0; i < P; i++) {
    cin >> goals[i];
  }

  for (int goal : goals) {
    int airport = ds.findNode(goal);
    if (airport != 0) {
      ds.merge(airport, airport - 1);
      answer += 1;
    } else {
      break;
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