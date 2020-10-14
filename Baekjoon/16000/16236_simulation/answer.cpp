#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct Shark {
  Axis axis;
  int size;
  int count;
};

struct Status {
  Axis axis;
  int depth;
};

int board[20][20];
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Axis limit;

bool compare(Axis a, Axis b) {
  if (a.y != b.y) return a.y < b.y;
  return a.x < b.x;
}

void solution() {
  int N;
  long long time = 0;
  cin >> N;

  limit.y = limit.x = N;
  Shark babyShark = {{0, 0}, 2, 0};

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];

      if (board[y][x] == 9) {
        babyShark.axis = {y, x};
        board[y][x] = 0;
      }
    }
  }

  while (true) {
    bool visited[20][20] = {
        0,
    };
    queue<Status> q;
    q.push({babyShark.axis, 0});

    vector<Axis> v;
    int distance = 0;
    bool findFish = false;

    while (!q.empty()) {
      if (findFish) break;

      int size = q.size();

      while (size != 0) {
        size -= 1;

        Status cur = q.front();
        q.pop();
        Axis axis = cur.axis;

        if (visited[axis.y][axis.x]) continue;
        visited[axis.y][axis.x] = true;

        if (board[axis.y][axis.x] < babyShark.size && board[axis.y][axis.x] != 0) {
          v.push_back(axis);
          distance = cur.depth;
          findFish = true;
          continue;
        }

        for (Axis dir : dirs) {
          Axis next = axis;
          next.y += dir.y;
          next.x += dir.x;

          if (next.x < 0 || next.x >= limit.x || next.y < 0 || next.y >= limit.y) continue;
          if (board[next.y][next.x] > babyShark.size) continue;

          q.push({next, cur.depth + 1});
        }
      }
    }

    if (v.empty()) break;
    sort(v.begin(), v.end(), compare);
    Axis target = v.front();

    time += distance;
    babyShark.axis = target;
    babyShark.count += 1;
    if (babyShark.count == babyShark.size) {
      babyShark.size += 1;
      babyShark.count = 0;
    }
    board[target.y][target.x] = 0;
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