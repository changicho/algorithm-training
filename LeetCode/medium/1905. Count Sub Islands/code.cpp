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

  Axis dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int rows = grid1.size(), cols = grid1[0].size();

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid2[y][x] == 0 || grid1[y][x] == 0) continue;

        bool isCovered = true;
        queue<Axis> q;
        q.push({y, x});
        grid2[y][x] = 0;

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          for (Axis& dir : dirs) {
            Axis next = {cur.y + dir.y, cur.x + dir.x};

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
              continue;
            if (grid2[next.y][next.x] == 0) continue;
            if (grid1[next.y][next.x] == 0) {
              isCovered = false;
              continue;
            }
            grid2[next.y][next.x] = 0;
            q.push(next);
          }
        }

        answer += isCovered;
      }
    }

    return answer;
  }
};