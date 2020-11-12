#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  int node, depth;
};

bool graph[51][51];

int N;
int friendsCount = 0;
bool visited[50];

int BFS(int vertex) {
  queue<Status> q;

  q.push({vertex, 0});
  visited[vertex] = true;

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.depth == 2) break;

    for (int next = 0; next < N; next++) {
      if (graph[cur.node][next] && !visited[next]) {
        visited[next] = true;
        q.push({next, cur.depth + 1});
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < N; i++) {
    ret += visited[i];
  }

  return ret - 1;
}

void solution() {
  int answer = 0;
  cin >> N;

  for (int y = 0; y < N; y++) {
    string line;
    cin >> line;

    for (int x = 0; x < N; x++) {
      graph[y][x] = line[x] == 'N' ? false : true;
    }
  }

  for (int node = 0; node < N; node++) {
    memset(visited, false, sizeof(visited));
    int newCount = BFS(node);
    answer = max(answer, newCount);
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