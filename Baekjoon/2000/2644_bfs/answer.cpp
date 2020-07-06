#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  int from, to;

  cin >> N;
  cin >> from >> to;

  vector<vector<int> > relations(N + 1);

  cin >> M;

  for (int i = 0; i < M; i++) {
    int temp_from, temp_to;
    cin >> temp_from >> temp_to;

    relations[temp_from].push_back(temp_to);
    relations[temp_to].push_back(temp_from);
  }

  bool visited[101] = {false};

  queue<int> q;
  q.push(from);
  visited[from] = true;

  int answer = 0;
  bool isEnd = false;
  while (!q.empty()) {
    int q_size = q.size();

    for (int size = 0; size < q_size; size++) {
      int cur = q.front();
      q.pop();

      if (cur == to) {
        isEnd = true;
        break;
      }

      for (int temp_to : relations[cur]) {
        if (visited[temp_to]) continue;

        q.push(temp_to);
        visited[temp_to] = true;
      }
    }

    if (isEnd) break;
    answer++;
  }

  if (visited[to]) {
    cout << answer << "\n";
  } else {
    cout << "-1\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}