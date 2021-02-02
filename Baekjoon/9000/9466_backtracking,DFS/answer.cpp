#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define LIMIT 100001

using namespace std;

int graph[LIMIT];
bool visited[LIMIT];
bool isFilled[LIMIT];
bool isDone[LIMIT];

void fillRecursive(int node) {
  isFilled[node] = true;
  int next = graph[node];

  if (isFilled[next]) {
    return;
  }

  fillRecursive(next);
}

void recursive(int node) {
  visited[node] = true;

  int next = graph[node];
  if (!visited[next]) {
    recursive(next);
  } else if (!isDone[next]) {
    fillRecursive(next);
  }

  isDone[node] = true;
}

void solution() {
  int N;
  cin >> N;

  for (int node = 1; node <= N; node++) {
    cin >> graph[node];
  }

  for (int node = 1; node <= N; node++) {
    if (visited[node]) {
      continue;
    }

    recursive(node);
  }

  int answer = 0;
  for (int node = 1; node <= N; node++) {
    answer += !isFilled[node];
  }

  cout << answer << "\n";
}

void init() {
  memset(visited, false, sizeof(visited));
  memset(isFilled, false, sizeof(isFilled));
  memset(isDone, false, sizeof(isDone));
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