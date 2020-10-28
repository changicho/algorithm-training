#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> links;
vector<bool> visited;

void recursive(int cur) {
  if (visited[cur]) return;

  visited[cur] = true;

  for (int to : links[cur]) {
    if (visited[to]) continue;

    recursive(to);
  }
}

void solution() {
  int N, M;
  int answer = 0;
  cin >> N >> M;

  links.resize(N + 1);
  visited.resize(N + 1, false);

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    links[from].push_back(to);
    links[to].push_back(from);
  }

  for (int cur = 1; cur <= N; cur++) {
    if (visited[cur]) continue;
    answer += 1;
    recursive(cur);
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