#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Status {
  int index, color;
};

using namespace std;

void solution() {
  int V, E;
  bool isBinary = true;

  cin >> V >> E;
  vector<vector<int> > links(V + 1);
  vector<int> colors(V + 1);

  for (int i = 0; i < E; i++) {
    int from, to;
    cin >> from >> to;
    links[from].push_back(to);
    links[to].push_back(from);
  }

  for (int start = 1; start <= V; start++) {
    if (colors[start] != 0) continue;

    queue<Status> q;
    q.push({start, 1});

    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      if (colors[cur.index] != 0 && colors[cur.index] != cur.color) {
        isBinary = false;
        break;
      }
      if (colors[cur.index] != 0) {
        continue;
      }
      colors[cur.index] = cur.color;

      for (int next : links[cur.index]) {
        q.push({next, -cur.color});
      }
    }
  }

  if (isBinary) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./data/input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    solution();
  }

  return 0;
}