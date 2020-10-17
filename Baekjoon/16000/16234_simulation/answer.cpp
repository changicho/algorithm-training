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
Axis limit;
int board[51][51];

void solution() {
  int N, L, R;
  int time = 0;
  cin >> N >> L >> R;
  limit = {N, N};

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  while (time <= 2000) {
    vector<vector<Axis> > group_axis(50 * 50 + 1);
    int group[51][51] = {
        0,
    };

    int group_count = 1;
    for (int y = 0; y < limit.y; y++) {
      for (int x = 0; x < limit.x; x++) {
        if (group[y][x] != 0) continue;

        int target = board[y][x];
        queue<Axis> q;
        q.push({y, x});

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          if (group[cur.y][cur.x] != 0) continue;
          group[cur.y][cur.x] = group_count;

          for (Axis dir : dirs) {
            Axis next = cur;
            next.y += dir.y;
            next.x += dir.x;

            if (next.y < 0 || next.y >= limit.y || next.x < 0 || next.x >= limit.x) continue;
            if (group[next.y][next.x] != 0) continue;
            int diff = abs(board[cur.y][cur.x] - board[next.y][next.x]);
            if (L > diff || diff > R) continue;

            q.push(next);
          }
        }
        group_count += 1;
      }
    }

    if (group_count - 1 == (limit.y * limit.x)) break;

    for (int y = 0; y < limit.y; y++) {
      for (int x = 0; x < limit.x; x++) {
        group_axis[group[y][x]].push_back({y, x});
      }
    }

    for (int i = 1; i < group_count; i++) {
      if (group_axis[i].size() == 1) continue;
      int sum = 0;

      for (Axis a : group_axis[i]) {
        sum += board[a.y][a.x];
      }
      int new_value = sum / group_axis[i].size();

      for (Axis a : group_axis[i]) {
        board[a.y][a.x] = new_value;
      }
    }

    time++;
  }

  cout << time << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}