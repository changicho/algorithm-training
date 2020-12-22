#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int N;
vector<Axis> axises;
bool visited[102];
bool graphs[102][102];

int getLength(Axis a, Axis b) {
  return abs(a.y - b.y) + abs(a.x - b.x);
}

bool canReach(Axis a, Axis b) {
  return getLength(a, b) <= 1000 ? true : false;
}

void recursive(int from) {
  visited[from] = true;

  for (int to = 0; to < axises.size(); to++) {
    if (!graphs[from][to]) continue;
    if (visited[to]) continue;

    recursive(to);
  }
}

void solution() {
  cin >> N;

  axises.resize(N + 2);

  for (int i = 0; i < N + 2; i++) {
    cin >> axises[i].x >> axises[i].y;
  }

  for (int from = 0; from < N + 2; from++) {
    for (int to = 0; to < N + 2; to++) {
      if (from == to) continue;

      if (canReach(axises[from], axises[to])) {
        graphs[from][to] = true;
        graphs[to][from] = true;
      }
    }
  }

  recursive(0);

  if (visited[axises.size() - 1]) {
    cout << "happy\n";
  } else {
    cout << "sad\n";
  }
}

void init() {
  memset(graphs, 0, sizeof(graphs));
  memset(visited, 0, sizeof(visited));
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    init();
    solution();
  }

  return 0;
}