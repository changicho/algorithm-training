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

// simulation
// time : O(RC)
// space : O(RC)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  unordered_map<char, Axis> dirMap = {
      {'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};

 public:
  vector<int> lastVisitedCell(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    Axis cur = {0, 0};
    visited[0][0] = true;
    while (true) {
      Axis dir = dirMap[grid[cur.y][cur.x]];

      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) break;
      if (visited[next.y][next.x]) break;
      visited[next.y][next.x] = true;
      cur = next;
    }
    return {cur.y, cur.x};
  }
};