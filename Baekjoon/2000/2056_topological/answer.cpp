#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int inDegree[10001] = {
      0,
  };
  int times[10001] = {
      0,
  };
  int costs[10001] = {
      0,
  };
  int N;
  int answer = 0;

  cin >> N;

  vector<vector<int> > graph(N + 1);

  int cost, size, to;
  for (int node = 1; node <= N; node++) {
    cin >> cost >> size;

    costs[node] = times[node] = cost;
    while (size--) {
      cin >> to;

      graph[to].push_back(node);
      inDegree[node] += 1;
    }
  }

  queue<int> q;
  for (int node = 1; node <= N; node++) {
    if (inDegree[node] == 0) {
      q.push(node);
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : graph[cur]) {
      times[next] = max(times[next], costs[next] + times[cur]);

      inDegree[next] -= 1;
      if (inDegree[next] == 0) {
        q.push(next);
      }
    }
  }

  for (int node = 1; node <= N; node++) {
    answer = max(answer, times[node]);
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