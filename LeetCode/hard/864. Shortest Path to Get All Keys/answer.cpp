#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(R * C * 2^K)
// space : O(R * C * 2^K)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  struct Data {
    int y, x, cost;
    int bitMask = 0;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  Axis getStart(vector<string>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == '@') return {y, x};
      }
    }
    return {-1, -1};
  }

  int getKeyCount(vector<string>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    int count = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (islower(grid[y][x])) count++;
      }
    }
    return count;
  }

 public:
  int shortestPathAllKeys(vector<string>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    Axis start = getStart(grid);
    int keys = getKeyCount(grid);

    vector<vector<vector<int>>> visited(
        1 << 6, vector<vector<int>>(rows, vector<int>(cols, INT_MAX)));

    queue<Data> q;
    q.push({start.y, start.x, 0, 0});

    int answer = INT_MAX;
    while (!q.empty()) {
      Data cur = q.front();
      q.pop();

      // get key
      if (islower(grid[cur.y][cur.x])) {
        cur.bitMask |= 1 << (grid[cur.y][cur.x] - 'a');
      }

      if (visited[cur.bitMask][cur.y][cur.x] <= cur.cost) continue;
      visited[cur.bitMask][cur.y][cur.x] = cur.cost;

      // has all key
      if (((1 << keys) - 1) == cur.bitMask) {
        answer = cur.cost;
        break;
      }

      for (Axis& dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (grid[next.y][next.x] == '#') continue;
        if (isupper(grid[next.y][next.x])) {
          int target = grid[next.y][next.x] - 'A';

          if ((cur.bitMask & (1 << target)) == 0) continue;
        }

        q.push({next.y, next.x, cur.cost + 1, cur.bitMask});
      }
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};