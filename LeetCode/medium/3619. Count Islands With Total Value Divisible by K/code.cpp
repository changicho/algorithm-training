#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// BFS
// time : O(RC)
// space : O(RC)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int countIslands(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;
        if (visited[y][x]) continue;

        queue<Axis> q;
        q.push({y, x});
        visited[y][x] = true;
        long long sum = grid[y][x];
        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          for (Axis& d : dirs) {
            Axis next = {cur.y + d.y, cur.x + d.x};

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
              continue;
            if (grid[next.y][next.x] == 0) continue;
            if (visited[next.y][next.x]) continue;
            visited[next.y][next.x] = true;
            sum += grid[next.y][next.x];
            q.push(next);
          }
        }

        if (sum % k == 0) answer++;
      }
    }

    return answer;
  }
};