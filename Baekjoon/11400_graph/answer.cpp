#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int V, E, answer;
int start_node = 1;

vector<vector<int>> graph;
vector<int> discovered;
// from, to
vector<pair<int, int>> cutLines;

int findCutLine(int here, int parent) {
  discovered[here] = start_node;
  start_node += 1;

  int ret = discovered[here];

  for (int next : graph[here]) {
    if (next == parent) continue;

    if (discovered[next]) {
      ret = min(ret, discovered[next]);
      continue;
    }

    int prev = findCutLine(next, here);

    if (prev > discovered[here]) {
      int from = min(here, next);
      int to = max(here, next);

      cutLines.push_back({from, to});
    }

    ret = min(ret, prev);
  }

  return ret;
}

void solution() {
  cin >> V >> E;

  graph.resize(V + 2);
  discovered.resize(V + 2);

  for (int i = 0; i < E; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (int i = 1; i <= V; i++) {
    if (!discovered[i]) findCutLine(i, 0);
  }

  sort(cutLines.begin(), cutLines.end());

  cout << cutLines.size() << "\n";
  for (auto cut : cutLines) {
    cout << cut.first << " " << cut.second << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}