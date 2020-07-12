#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Tower {
  vector<char> v;
  char target;
};

struct Status {
  Tower tower[3];
  int count;
};

set<string> visited;

bool checking(Status status) {
  bool ret = true;

  for (Tower tower : status.tower) {
    int count = 0;
    for (char c : tower.v) {
      if (c == tower.target) count += 1;
    }

    if (tower.v.size() != count) {
      ret = false;
      break;
    }
  }

  return ret;
}

string change(Status status) {
  string ret = "";

  for (int i = 0; i < 3; i++) {
    string line = "";
    for (char c : status.tower[i].v) {
      line += c;
    }
    ret += line + "/";
  }
  return ret;
}

void solution() {
  int size;
  int answer = 0;
  Status status;
  string line;

  status.tower[0].target = 'A';
  status.tower[1].target = 'B';
  status.tower[2].target = 'C';
  status.count = 0;

  for (int i = 0; i < 3; i++) {
    cin >> size;
    if (size == 0) continue;
    cin >> line;
    for (char c : line) {
      status.tower[i].v.push_back(c);
    }
  }

  queue<Status> q;
  q.push(status);

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (checking(cur)) {
      answer = cur.count;
      break;
    }
    string status_string = change(cur);
    if (visited.find(status_string) != visited.end()) continue;
    visited.insert(status_string);

    for (int from = 0; from < 3; from++) {
      for (int to = 0; to < 3; to++) {
        if (from == to) continue;
        Status next = cur;
        if (next.tower[from].v.empty()) continue;

        char target = next.tower[from].v.back();
        next.tower[to].v.push_back(target);
        next.tower[from].v.pop_back();

        next.count += 1;
        q.push(next);
      }
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