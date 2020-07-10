#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  int screen, clip, count;
};

bool visited[1002][1002];

void solution() {
  int S;
  int answer = 0;
  cin >> S;

  queue<Status> q;
  q.push({1, 0, 0});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.screen == S) {
      answer = cur.count;
      break;
    }

    if (cur.screen < 0 || cur.clip < 0) continue;
    if (cur.screen > 1001 || cur.clip > 1001) continue;
    if (visited[cur.screen][cur.clip]) continue;
    visited[cur.screen][cur.clip] = true;

    q.push({cur.screen, cur.screen, cur.count + 1});
    q.push({cur.screen + cur.clip, cur.clip, cur.count + 1});
    q.push({cur.screen - 1, cur.clip, cur.count + 1});
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}