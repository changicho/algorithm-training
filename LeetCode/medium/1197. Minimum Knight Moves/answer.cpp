#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[8] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                  {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

 public:
  int minKnightMoves(int x, int y) {
    const int HALF = 302;
    bool visited[604][604] = {false};
    visited[0 + HALF][0 + HALF] = true;

    queue<Axis> q;
    q.push({0, 0});

    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        Axis cur = q.front();
        q.pop();

        if (abs(cur.y) + abs(cur.x) > 300) continue;
        if (cur.y == y && cur.x == x) return step;

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (visited[next.y + HALF][next.x + HALF]) continue;
          visited[next.y + HALF][next.x + HALF] = true;
          q.push(next);
        }
      }
      step++;
    }

    return -1;
  }
};