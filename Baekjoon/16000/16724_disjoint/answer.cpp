#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

bool compare(Axis a, Axis b) {
  if (a.y != b.y) {
    return a.y > b.y;
  }
  return a.x > b.x;
}

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M;
char board[1001][1001];

Axis getDir(char dir) {
  switch (dir) {
    case 'U': {
      return dirs[0];
    }
    case 'D': {
      return dirs[2];
    }
    case 'L': {
      return dirs[3];
    }
    case 'R': {
      return dirs[1];
    }
  }
  return dirs[0];
}

struct DisjointSet {
  vector<vector<Axis>> parents;
  vector<vector<int>> counts;

  DisjointSet(int row, int col) {
    parents.resize(row, vector<Axis>(col));
    counts.resize(row, vector<int>(col));

    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        parents[y][x] = {y, x};
        counts[y][x] = 1;
      }
    }
  }

  Axis findNode(Axis node) {
    Axis parent = parents[node.y][node.x];
    if (parent.y == node.y && parent.x == node.x) {
      return node;
    }

    return parents[node.y][node.x] = findNode(parent);
  }

  bool isLinked(Axis nodeA, Axis nodeB) {
    Axis parentA = findNode(nodeA), parentB = findNode(nodeB);
    return (parentA.y == parentB.y && parentA.x == parentB.x);
  }

  void merge(Axis nodeA, Axis nodeB) {
    if (compare(nodeA, nodeB)) {
      swap(nodeA, nodeB);
    }

    nodeA = findNode(nodeA);
    nodeB = findNode(nodeB);

    if (nodeA.y == nodeB.y && nodeA.x == nodeB.x) return;
    if (counts[nodeA.y][nodeA.x] < counts[nodeB.y][nodeB.x]) {
      swap(nodeA, nodeB);
    }

    parents[nodeB.y][nodeB.x] = nodeA;
    if (counts[nodeA.y][nodeA.x] == counts[nodeB.y][nodeB.x]) {
      counts[nodeB.y][nodeB.x]++;
    }
  }
};

void solution() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> board[y][x];
    }
  }

  DisjointSet ds(N, M);
  int answer = N * M;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      Axis dir = getDir(board[y][x]);
      Axis cur = {y, x}, next = {y + dir.y, x + dir.x};

      if (!ds.isLinked(cur, next)) {
        ds.merge(cur, next);
        answer -= 1;
      }
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