#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  int index, count;
};

bool visited[501];
vector<vector<int> > links;

void solution() {
  int N, M;

  cin >> N >> M;

  links.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    links[a].push_back(b);
    links[b].push_back(a);
  }

  queue<Status> q;
  q.push({1, 0});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (visited[cur.index]) continue;
    if (cur.count > 2) continue;
    visited[cur.index] = true;

    for (int to : links[cur.index]) {
      q.push({to, cur.count + 1});
    }
  }

  int answer = 0;
  for (int i = 2; i < N + 1; i++) {
    visited[i] ? answer += 1 : NULL;
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