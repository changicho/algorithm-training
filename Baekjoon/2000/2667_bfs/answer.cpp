#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isFine(Axis axis, Axis limit) { return (axis.y < 0 || axis.y >= limit.y || axis.x < 0 || axis.x >= limit.x) ? false : true; }

void solution() {
  bool board[25][25];
  bool visited[25][25] = {
      false,
  };
  vector<int> answers;

  int N;
  cin >> N;

  for (int y = 0; y < N; y++) {
    string line;
    cin >> line;
    for (int x = 0; x < N; x++) {
      board[y][x] = line[x] == '0' ? false : true;
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (visited[y][x] || board[y][x] == 0) continue;
      int count = 0;

      queue<Axis> q;
      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;
        count += 1;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (!isFine(next, {N, N})) continue;
          if (board[next.y][next.x] == 0) continue;

          q.push(next);
        }
      }

      answers.push_back(count);
    }
  }

  sort(answers.begin(), answers.end());

  cout << answers.size() << "\n";
  for (int answer : answers) {
    cout << answer << "\n";
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