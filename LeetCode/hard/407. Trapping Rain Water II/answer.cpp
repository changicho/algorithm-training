#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use priority queue

class Solution {
 private:
  struct Axis {
    int y, x;
    Axis operator+(const Axis &b) const { return {y + b.y, x + b.x}; }
  };

  struct Status {
    int height;
    Axis axis;

    bool operator<(const Status &b) const { return height > b.height; };
  };

  vector<Axis> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    int rows = heightMap.size();
    int cols = heightMap.front().size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    priority_queue<Status> pq;

    for (int y = 0; y < rows; y++) {
      pq.push({heightMap[y][0], {y, 0}});
      pq.push({heightMap[y][cols - 1], {y, cols - 1}});

      visited[y][0] = true;
      visited[y][cols - 1] = true;
    }
    for (int x = 1; x < cols - 1; x++) {
      pq.push({heightMap[0][x], {0, x}});
      pq.push({heightMap[rows - 1][x], {rows - 1, x}});

      visited[0][x] = true;
      visited[rows - 1][x] = true;
    }

    int answer = 0;
    int maximum = INT_MIN;
    while (!pq.empty()) {
      Status cur = pq.top();
      Axis &axis = cur.axis;
      pq.pop();

      maximum = max(maximum, cur.height);

      for (Axis &dir : dirs) {
        Axis next = axis + dir;

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[next.y][next.x]) continue;
        visited[next.y][next.x] = true;

        if (heightMap[next.y][next.x] < maximum) {
          answer += maximum - heightMap[next.y][next.x];
        }

        pq.push({heightMap[next.y][next.x], next});
      }
    }

    return answer;
  }
};