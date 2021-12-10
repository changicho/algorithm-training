#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS

class Solution {
 private:
  struct Axis {
    int y, x;
  };
  struct Status {
    Axis axis;
    int crash;

    string convert() {
      return to_string(axis.y) + "," + to_string(axis.x) + "," +
             to_string(crash);
    }
  };

  vector<Axis> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid.front().size();

    queue<Status> q;
    unordered_set<string> visited;
    Status start = {{0, 0}, 0};
    visited.insert(start.convert());
    if (grid[0][0] == 1) start.crash += 1;

    q.push(start);

    int step = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Status cur = q.front();
        q.pop();

        Axis& axis = cur.axis;
        if (axis.y == rows - 1 && axis.x == cols - 1) return step;

        for (Axis& dir : dirs) {
          Axis next = {dir.y + axis.y, dir.x + axis.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
            continue;
          }

          Status nextStatus = {next, cur.crash + grid[next.y][next.x]};
          if (nextStatus.crash > k) continue;

          if (visited.find(nextStatus.convert()) != visited.end()) continue;
          visited.insert(nextStatus.convert());
          q.push(nextStatus);
        }
      }
      step++;
    }

    return -1;
  }
};

// use visited check BFS

class Solution {
 private:
  struct Axis {
    int y, x;
  };
  struct Status {
    Axis axis;
    int crash;
  };

  vector<Axis> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<Status> q;
    vector<vector<int>> visited(rows, vector<int>(cols, INT_MAX));

    q.push({{0, 0}, grid[0][0]});
    visited[0][0] = grid[0][0];

    int steps = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Status cur = q.front();
        q.pop();
        Axis axis = cur.axis;
        int crash = cur.crash;

        if (axis.y == rows - 1 && axis.x == cols - 1) {
          return steps;
        }

        for (Axis& dir : dirs) {
          Axis next = {axis.y + dir.y, axis.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          int nextCrash = crash + grid[next.y][next.x];

          if (nextCrash > k) continue;
          if (nextCrash < visited[next.y][next.x]) {
            visited[next.y][next.x] = nextCrash;
            q.push({next, nextCrash});
          }
        }
      }
      steps++;
    }
    return -1;
  }
};