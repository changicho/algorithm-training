#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;

    Axis operator+(const Axis &b) const { return {y + b.y, x + b.x}; }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int findMaxFish(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;

        int count = grid[y][x];
        grid[y][x] = 0;
        queue<Axis> q;
        q.push({y, x});

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          for (Axis &dir : dirs) {
            Axis next = cur + dir;

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
              continue;
            if (grid[next.y][next.x] == 0) continue;

            count += grid[next.y][next.x];
            grid[next.y][next.x] = 0;
            q.push(next);
          }
        }

        answer = max(answer, count);
      }
    }

    return answer;
  }
};