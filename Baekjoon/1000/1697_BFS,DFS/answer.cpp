#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  int axis;
  int depth;
};

void solution() {
  int table[200001];
  memset(table, -1, sizeof(table));

  int N, K;
  int answer;
  cin >> N >> K;
  table[N] = 0;

  answer = abs(K - N);

  queue<Status> q;
  q.push({N, 0});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.axis < 0 || cur.axis > 2 * K) continue;
    if (table[cur.axis] != -1 && table[cur.axis] < cur.depth) continue;
    table[cur.axis] = cur.depth;

    if (cur.axis == K) {
      answer = cur.depth;

      while (!q.empty()) q.pop();
      continue;
    }

    q.push({cur.axis + 1, cur.depth + 1});
    q.push({cur.axis - 1, cur.depth + 1});
    q.push({cur.axis * 2, cur.depth + 1});
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