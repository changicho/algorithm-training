#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  long long number, depth;
};

void solution() {
  map<long long, long long> counts;
  queue<Status> q;

  long long A, B;
  long long answer = -1;
  cin >> A >> B;

  q.push({A, 1});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.number == B) {
      answer = cur.depth;
      break;
    }
    if (counts[cur.number] != 0) continue;
    counts[cur.number] = cur.depth;

    if (cur.number * 2 <= B) {
      q.push({cur.number * 2, cur.depth + 1});
    }
    if (cur.number * 10 + 1 <= B) {
      q.push({cur.number * 10 + 1, cur.depth + 1});
    }
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