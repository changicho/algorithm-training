#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int V, E, answer;
int start_node = 1;

vector<vector<int> > graph;
vector<int> discovered;
vector<bool> isCut;

int findCut(int here, bool isRoot) {
  discovered[here] = start_node;
  start_node += 1;

  int ret = discovered[here];
  int child = 0;

  for (int next : graph[here]) {
    if (discovered[next]) {
      ret = min(ret, discovered[next]);
      continue;
    }

    child++;
    int prev = findCut(next, false);

    if (!isRoot && prev >= discovered[here]) isCut[here] = true;

    ret = min(ret, prev);
  }

  if (isRoot) {
    if (child >= 2) {
      isCut[here] = true;
    }
  }

  return ret;
}

void solution() {
  cin >> V >> E;

  graph.resize(V + 1);
  discovered.resize(V + 1);
  isCut.resize(V + 1);

  for (int i = 0; i < E; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (int i = 1; i <= V; i++) {
    if (!discovered[i]) findCut(i, true);
  }

  for (int i = 1; i <= V; i++) {
    if (isCut[i]) answer += 1;
  }
  cout << answer << "\n";

  for (int i = 1; i <= V; i++) {
    if (isCut[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}