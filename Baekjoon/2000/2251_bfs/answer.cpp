#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Bottle {
  int b[3];
};

string change(Bottle bottle) {
  string s = to_string(bottle.b[0]) + "/" + to_string(bottle.b[1]);
  return s;
}
set<string> s;

void solution() {
  Bottle limit;
  vector<int> answers;

  cin >> limit.b[0] >> limit.b[1] >> limit.b[2];

  queue<Bottle> q;
  q.push({0, 0, limit.b[2]});

  while (!q.empty()) {
    Bottle cur = q.front();
    q.pop();

    string status = change(cur);
    if (s.find(status) != s.end()) continue;
    s.insert(status);

    if (cur.b[0] == 0) {
      answers.push_back(cur.b[2]);
    }

    for (int from = 0; from < 3; from++) {
      for (int to = 0; to < 3; to++) {
        if (from == to) continue;
        Bottle next = cur;

        if (next.b[to] + next.b[from] > limit.b[to]) {
          next.b[from] = next.b[to] + next.b[from] - limit.b[to];
          next.b[to] = limit.b[to];
        } else {
          next.b[to] = next.b[to] + next.b[from];
          next.b[from] = 0;
        }

        q.push(next);
      }
    }
  }

  sort(answers.begin(), answers.end());
  answers.erase(unique(answers.begin(), answers.end()), answers.end());

  for (int answer : answers) {
    cout << answer << " ";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}