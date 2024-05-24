#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

 public:
  int numberOfCleanRooms(vector<vector<int>>& room) {
    int rows = room.size(), cols = room[0].size();

    int dir = 0;

    bool visited[300][300][4] = {
        false,
    };
    Axis cur = {0, 0};
    while (visited[cur.y][cur.x][dir] == false) {
      visited[cur.y][cur.x][dir] = true;

      Axis d = dirs[dir];
      Axis next = {cur.y + d.y, cur.x + d.x};

      // change
      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols ||
          room[next.y][next.x] == 1) {
        dir = (dir + 1) % 4;
        continue;
      }

      cur = next;
    }

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer += visited[y][x][0] || visited[y][x][1] || visited[y][x][2] ||
                  visited[y][x][3];
      }
    }
    return answer;
  }
};