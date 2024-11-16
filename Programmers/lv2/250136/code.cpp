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
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solution(vector<vector<int>> land) {
  int rows = land.size(), cols = land[0].size();

  vector<vector<int>> colors(rows, vector<int>(cols, -1));
  vector<int> sizes;

  int color = 0;
  queue<Axis> q;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (land[y][x] == 0) continue;

      int size = 0;
      q.push({y, x});
      vector<Axis> path;
      land[y][x] = 0;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        path.push_back(cur);

        size++;

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (land[next.y][next.x] == 0) continue;

          land[next.y][next.x] = 0;
          q.push(next);
        }
      }

      for (Axis &p : path) {
        colors[p.y][p.x] = color;
      }
      color++;
      sizes.push_back(size);
    }
  }

  int answer = 0;

  for (int x = 0; x < cols; x++) {
    unordered_set<int> us;
    for (int y = 0; y < rows; y++) {
      if (colors[y][x] == -1) continue;
      us.insert(colors[y][x]);
    }

    int cur = 0;
    for (int c : us) {
      cur += sizes[c];
    }
    answer = max(answer, cur);
  }

  return answer;
}