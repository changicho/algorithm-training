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

    Axis operator+(const Axis& B) const {
      return {y + B.y, x + B.x};
    }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid.front().size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int answer = 0;
    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        if (visited[y][x] || grid[y][x] == 0) continue;

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
            Axis next = cur + dir;

            if (next.y < 0 || next.y >= row || next.x < 0 || next.x >= col) continue;
            if (grid[next.y][next.x] == 0) continue;
            q.push(next);
          }
        }

        answer = max(answer, count);
      }
    }

    return answer;
  }
};

// use BFS check next

class Solution {
 private:
  struct Axis {
    int y, x;

    Axis operator+(const Axis& B) const {
      return {y + B.y, x + B.x};
    }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid.front().size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int answer = 0;
    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        if (visited[y][x] || grid[y][x] == 0) continue;

        int count = 0;
        queue<Axis> q;
        q.push({y, x});
        visited[y][x] = true;

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          count += 1;

          for (Axis dir : dirs) {
            Axis next = cur + dir;

            if (next.y < 0 || next.y >= row || next.x < 0 || next.x >= col) continue;
            if (grid[next.y][next.x] == 0) continue;
            if (visited[next.y][next.x]) continue;
            visited[next.y][next.x] = true;
            q.push(next);
          }
        }

        answer = max(answer, count);
      }
    }

    return answer;
  }
};