#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visited[101];
int matchingTable[101];

vector<vector<int>> graph;

int recursive(int from) {
  if (visited[from]) return false;

  visited[from] = true;

  for (int to : graph[from]) {
    if (matchingTable[to] == 0 || recursive(matchingTable[to])) {
      matchingTable[to] = from;

      return true;
    }
  }
  return false;
}

void solution() {
  int N, M;
  int answer = 0;

  cin >> N >> M;

  graph.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
  }

  for (int node = 1; node <= N; node++) {
    memset(visited, 0, sizeof(visited));

    if (recursive(node)) answer++;
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