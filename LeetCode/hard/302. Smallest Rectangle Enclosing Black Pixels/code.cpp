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
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int yMax = INT_MIN, yMin = INT_MAX;
    int xMax = INT_MIN, xMin = INT_MAX;

    int rows = image.size(), cols = image[0].size();

    queue<Axis> q;
    image[x][y] = '0';
    q.push({x, y});
    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      yMax = max(cur.y, yMax);
      yMin = min(cur.y, yMin);
      xMax = max(cur.x, xMax);
      xMin = min(cur.x, xMin);

      for (Axis& dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (image[next.y][next.x] == '0') continue;
        image[next.y][next.x] = '0';
        q.push(next);
      }
    }

    int yDiff = (yMax - yMin) + 1;
    int xDiff = (xMax - xMin) + 1;

    return yDiff * xDiff;
  }
};

// use binary search
// time : O(R * log_2(C) + C * log_2(R))
// space : O(1)
class Solution {
 private:
  vector<vector<char>>* image;

  int searchRows(int from, int to, int low, int high, bool condition,
                 vector<vector<char>>& image) {
    while (from != to) {
      int target = low;
      int mid = (from + to) / 2;

      while (target < high && image[mid][target] == '0') target++;

      if (target < high == condition) {
        to = mid;
      } else {
        from = mid + 1;
      }
    }
    return from;
  }

  int searchColumns(int from, int to, int low, int high, bool condition,
                    vector<vector<char>>& image) {
    while (from != to) {
      int target = low;
      int mid = (from + to) / 2;

      while (target < high && image[target][mid] == '0') ++target;
      if (target < high == condition) {
        to = mid;
      } else {
        from = mid + 1;
      }
    }
    return from;
  }

 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    this->image = &image;

    int rows = image.size(), cols = image[0].size();

    int top = searchRows(0, x, 0, cols, true, image);
    int bottom = searchRows(x + 1, rows, 0, cols, false, image);

    int left = searchColumns(0, y, top, bottom, true, image);
    int right = searchColumns(y + 1, cols, top, bottom, false, image);

    return (right - left) * (bottom - top);
  }
};