#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  vector<int> history;
};

void solution() {
  int N;
  bool visited[1000001] = {
      false,
  };

  cin >> N;

  queue<Status> q;
  vector<int> answer;
  q.push({{N}});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    int node = cur.history.back();
    if (node == 1) {
      answer = cur.history;
      break;
    }
    if (visited[node]) continue;
    visited[node] = true;

    vector<int> new_history = cur.history;

    if (node % 3 == 0) {
      new_history.push_back(node / 3);
      q.push({new_history});
      new_history.pop_back();
    }
    if (node % 2 == 0) {
      new_history.push_back(node / 2);
      q.push({new_history});
      new_history.pop_back();
    }
    if (node - 1 > 0) {
      new_history.push_back(node - 1);
      q.push({new_history});
      new_history.pop_back();
    }
  }

  cout << answer.size() - 1 << "\n";
  for (int node : answer) {
    cout << node << " ";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}