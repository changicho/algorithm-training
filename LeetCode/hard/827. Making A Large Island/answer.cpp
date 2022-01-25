#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use color check BFS

class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int largestIsland(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int size = rows * cols;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    unordered_map<int, int> counts;
    vector<vector<int>> colors(rows, vector<int>(cols, -1));
    int color = 1;

    vector<Axis> zeros;
    int answer = 0;

    // flood fill
    // fill color and count color
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) {
          zeros.push_back({y, x});
          continue;
        }
        if (visited[y][x]) continue;

        vector<Axis> paths;
        queue<Axis> q;
        q.push({y, x});
        visited[y][x] = true;
        int count = 1;

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          paths.push_back(cur);

          for (Axis &dir : dirs) {
            Axis next = {cur.y + dir.y, cur.x + dir.x};

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
              continue;
            if (grid[next.y][next.x] == 0) continue;
            if (visited[next.y][next.x]) continue;

            visited[next.y][next.x] = true;
            count++;
            q.push(next);
          }
        }

        for (Axis &a : paths) {
          colors[a.y][a.x] = color;
        }
        counts[color] = count;

        color++;
        answer = max(answer, count);
      }
    }

    // iterate zero and count new sum
    for (Axis &axis : zeros) {
      unordered_set<int> linkedColors;
      int count = 1;

      for (Axis &dir : dirs) {
        Axis next = {axis.y + dir.y, axis.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (grid[next.y][next.x] == 0) continue;
        if (linkedColors.count(colors[next.y][next.x]) > 0) continue;

        linkedColors.insert(colors[next.y][next.x]);
        count += counts[colors[next.y][next.x]];
      }

      answer = max(answer, count);
    }

    return answer;
  }
};
