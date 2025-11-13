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

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  struct Status {
    Axis a;
    int h;
    bool isPacific;
  };

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows = heights.size(), cols = heights[0].size();

    bool visited[2][201][201] = {
        false,
    };

    queue<Status> q;
    for (int x = 0; x < cols; x++) {
      q.push({{-1, x}, -1, true});
      q.push({{rows, x}, -1, false});
    }
    for (int y = 0; y < rows; y++) {
      q.push({{y, -1}, -1, true});
      q.push({{y, cols}, -1, false});
    }

    while (!q.empty()) {
      Status cur = q.front();
      Axis a = cur.a;
      q.pop();

      for (Axis& dir : dirs) {
        Axis next = {a.y + dir.y, a.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[cur.isPacific][next.y][next.x]) continue;
        if (heights[next.y][next.x] < cur.h) continue;

        visited[cur.isPacific][next.y][next.x] = true;

        q.push({next, heights[next.y][next.x], cur.isPacific});
      }
    }

    vector<vector<int>> answer;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (visited[0][y][x] && visited[1][y][x]) {
          answer.push_back({y, x});
        }
      }
    }
    return answer;
  }
};