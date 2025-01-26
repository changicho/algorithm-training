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
  };

  Axis dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

 public:
  long long sumRemoteness(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    long long allSum = 0;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] != -1) allSum += grid[y][x];
      }
    }
    long long answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == -1) continue;

        long long curSum = 0;

        queue<Axis> q;
        q.push({y, x});
        curSum += grid[y][x];
        grid[y][x] = -1;
        int size = 1;
        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          for (Axis& dir : dirs) {
            Axis next = {cur.y + dir.y, cur.x + dir.x};

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
              continue;
            if (grid[next.y][next.x] == -1) continue;
            curSum += grid[next.y][next.x];
            size++;
            grid[next.y][next.x] = -1;
            q.push(next);
          }
        }

        answer += (allSum - curSum) * size;
      }
    }

    return answer;
  }
};