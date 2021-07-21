#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS

class Solution {
 private:
  struct Axis {
    int y, x;
    Axis operator+(const Axis& b) const {
      return {y + b.y, x + b.x};
    }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int answer = 0;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] != '1') continue;
        answer += 1;

        queue<Axis> q;
        q.push({y, x});

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          if (grid[cur.y][cur.x] != '1') continue;
          grid[cur.y][cur.x] = '2';

          for (Axis dir : dirs) {
            Axis next = cur + dir;

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
            if (grid[next.y][next.x] != '1') continue;

            q.push(next);
          }
        }
      }
    }

    return answer;
  }
};

// use DFS

class Solution {
 private:
  struct Axis {
    int y, x;
    Axis operator+(const Axis& b) const {
      return {y + b.y, x + b.x};
    }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  void recursive(Axis cur, vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    if (grid[cur.y][cur.x] != '1') return;
    grid[cur.y][cur.x] = '2';

    for (Axis dir : dirs) {
      Axis next = cur + dir;

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
      if (grid[next.y][next.x] != '1') continue;

      recursive(next, grid);
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int answer = 0;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] != '1') continue;
        answer += 1;

        recursive({y, x}, grid);
      }
    }

    return answer;
  }
};