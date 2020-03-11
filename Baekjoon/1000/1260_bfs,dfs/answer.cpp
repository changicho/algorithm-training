#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

vector<int> links[1001];

void dfs(int start) {
  stack<int> s;
  bool visited[1001] = {
      false,
  };

  visited[start] = true;
  s.push(start);
  cout << start << " ";

  while (!s.empty()) {
    bool flag = true;
    int current = s.top();

    for (int next : links[current]) {
      if (visited[next]) {
        continue;
      }

      visited[next] = true;
      s.push(next);
      cout << next << " ";

      flag = false;
      break;
    }

    if (flag) {
      s.pop();
    }
  }
  cout << "\n";
}

void bfs(int start) {
  queue<int> q;
  bool visited[1001] = {
      false,
  };

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    cout << current << " ";

    for (int next : links[current]) {
      if (visited[next]) {
        continue;
      }

      q.push(next);
      visited[next] = true;
    }
  }
  cout << "\n";
}

void solution() {
  int N, M, V;

  cin >> N >> M >> V;

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    links[from].push_back(to);
    links[to].push_back(from);

    sort(links[from].begin(), links[from].end());
    sort(links[to].begin(), links[to].end());
  }

  dfs(V);
  bfs(V);

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}