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

// use BFS by step
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    int rows = isWater.size(), cols = isWater[0].size();

    queue<Axis> q;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (isWater[y][x] == 1) {
          isWater[y][x] = 0;
          q.push({y, x});
        } else {
          isWater[y][x] = -1;
        }
      }
    }

    int level = 1;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Axis cur = q.front();
        q.pop();

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};
          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;

          if (isWater[next.y][next.x] != -1) continue;
          isWater[next.y][next.x] = level;

          q.push(next);
        }
      }

      level++;
    }

    return isWater;
  }
};