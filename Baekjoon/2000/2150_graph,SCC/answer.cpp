#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool visited[10000 + 1];

vector<vector<int>> scc;
vector<vector<int>> graph;
vector<vector<int>> graph_reverse;
stack<int> st;

inline bool compare(vector<int> a, vector<int> b) {
  return a.front() < b.front();
}

void dfs(int vertex) {
  visited[vertex] = true;

  for (int next : graph[vertex]) {
    if (visited[next]) {
      continue;
    }
    dfs(next);
  }
  st.push(vertex);
}

void dfs_reverse(int vertex, vector<int> *connected) {
  visited[vertex] = true;

  connected->push_back(vertex);

  for (int next : graph_reverse[vertex]) {
    if (visited[next]) {
      continue;
    }

    dfs_reverse(next, connected);
  }
}

void solution() {
  int V, E;
  cin >> V >> E;

  graph.resize(V + 1);
  graph_reverse.resize(V + 1);

  int from, to;
  for (int i = 0; i < E; i++) {
    cin >> from >> to;

    graph[from].push_back(to);
    graph_reverse[to].push_back(from);
  }

  for (int vertex = 1; vertex <= V; vertex++) {
    if (visited[vertex]) {
      continue;
    }
    dfs(vertex);
  }

  memset(visited, 0, sizeof(visited));

  while (!st.empty()) {
    int cur = st.top();
    st.pop();

    if (visited[cur]) {
      continue;
    }

    vector<int> connected;
    dfs_reverse(cur, &connected);
    scc.push_back(connected);
  }

  for (vector<int> &cur : scc) {
    sort(cur.begin(), cur.end());
  }
  sort(scc.begin(), scc.end(), compare);

  cout << scc.size() << "\n";

  for (vector<int> cur : scc) {
    for (int vertex : cur) {
      cout << vertex << " ";
    }
    cout << "-1\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}