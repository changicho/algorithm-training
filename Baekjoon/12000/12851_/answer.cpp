#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define LIMIT 100001

using namespace std;

struct Status {
  int axis, depth;
};

void solution() {
  int N, K;
  int answer = 100001;
  int answerCount = 0;

  cin >> N >> K;

  bool visited[200001] = {
      false,
  };

  queue<Status> q;
  q.push({N, 0});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();
    visited[cur.axis] = true;

    if (cur.axis == K && cur.depth <= answer) {
      answer = cur.depth;
      answerCount += 1;
      continue;
    }

    if (cur.axis + 1 < LIMIT && !visited[cur.axis + 1]) q.push({cur.axis + 1, cur.depth + 1});
    if (cur.axis - 1 >= 0 && !visited[cur.axis - 1]) q.push({cur.axis - 1, cur.depth + 1});
    if (cur.axis * 2 < LIMIT && !visited[cur.axis * 2]) q.push({cur.axis * 2, cur.depth + 1});
  }

  cout << answer << "\n"
       << answerCount << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}