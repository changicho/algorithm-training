#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  int axis, depth;
};

void solution() {
  int dist[100001] = {
      0,
  };
  for (int i = 0; i <= 100000; i++) {
    dist[i] = -1;
  }
  int N, K;
  cin >> N >> K;
  int limit = min(2 * max(N, K), 100000);

  queue<Status> q;
  q.push({N, 0});

  int answer = abs(K - N);

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.axis > limit || cur.axis < 0) continue;
    if (dist[cur.axis] != -1 && dist[cur.axis] <= cur.depth) continue;
    dist[cur.axis] = cur.depth;

    if (cur.axis == K) {
      answer = min(answer, cur.depth);
      continue;
    }

    q.push({cur.axis * 2, cur.depth});
    q.push({cur.axis + 1, cur.depth + 1});
    q.push({cur.axis - 1, cur.depth + 1});
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