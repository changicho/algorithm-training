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

// prefix sum & heap
// time : O(RC \* min(R, C))
// space : O(RC)
class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> rightDp(rows + 1, vector<int>(cols + 2));
    vector<vector<int>> leftDp(rows + 1, vector<int>(cols + 2));
    for (int y = 1; y <= rows; y++) {
      for (int x = 1; x <= cols; x++) {
        rightDp[y][x] = rightDp[y - 1][x - 1] + grid[y - 1][x - 1];
        leftDp[y][x] = leftDp[y - 1][x + 1] + grid[y - 1][x - 1];
      }
    }

    unordered_set<int> visited;
    priority_queue<int, vector<int>, greater<int>> pq;

    function<void(int)> add = [&](int sum) {
      if (visited.count(sum) == 0) {
        visited.insert(sum);
        pq.push(sum);
        if (pq.size() > 3) {
          visited.erase(pq.top());
          pq.pop();
        }
      }
    };

    for (int y = 0; y < rows; ++y) {
      for (int x = 0; x < cols; ++x) {
        add(grid[y][x]);

        for (int yy = y + 2; yy < rows; yy += 2) {
          int uy = y, ux = x;
          int dy = yy, dx = x;
          int ly = (y + yy) / 2, lx = x - (yy - y) / 2;
          int ry = (y + yy) / 2, rx = x + (yy - y) / 2;

          if (lx < 0 || rx >= cols) break;

          int topLeft = leftDp[ly + 1][lx + 1] - leftDp[uy][ux + 2];
          int topRight = rightDp[ry + 1][rx + 1] - rightDp[uy][ux];
          int bottomRight = rightDp[dy + 1][dx + 1] - rightDp[ly][lx];
          int bottomLeft = leftDp[dy + 1][dx + 1] - leftDp[ry][rx + 2];

          int duplicated =
              grid[uy][ux] + grid[dy][dx] + grid[ly][lx] + grid[ry][rx];

          int sum = topLeft + topRight + bottomRight + bottomLeft - duplicated;

          add(sum);
        }
      }
    }
    vector<int> answer;
    while (!pq.empty()) {
      answer.push_back(pq.top());
      pq.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// prefix sum & heap
// time : O(RC \* min(R, C))
// space : O(RC \* min(R, C))
class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<vector<int>>> topDp(
        rows, vector<vector<int>>(cols, vector<int>(51, INT_MIN)));
    vector<vector<vector<int>>> downDp(
        rows, vector<vector<int>>(cols, vector<int>(51, INT_MIN)));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        topDp[y][x][0] = 0;
        topDp[y][x][1] = grid[y][x];
        for (int l = 2; l <= 50; l++) {
          int diff = l - 1;

          if (x - diff < 0 || x + diff >= cols) break;
          if (y + diff >= rows) break;
          topDp[y][x][l] = topDp[y][x][l - 1] + grid[y + diff][x + diff] +
                           grid[y + diff][x - diff];
        }

        downDp[y][x][0] = 0;
        downDp[y][x][1] = grid[y][x];
        for (int l = 2; l <= 50; l++) {
          int diff = l - 1;

          if (x - diff < 0 || x + diff >= cols) break;
          if (y - diff < 0) break;
          downDp[y][x][l] = downDp[y][x][l - 1] + grid[y - diff][x + diff] +
                            grid[y - diff][x - diff];
        }
      }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> visited;
    function<void(int)> add = [&](int sum) {
      if (visited.count(sum) == 0) {
        visited.insert(sum);
        pq.push(sum);
        if (pq.size() > 3) {
          pq.pop();
        }
      }
    };
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        for (int l = 1; l <= 50; l++) {
          int diff = l - 1;
          if (y + 2 * diff >= rows) break;
          if (topDp[y][x][l] == INT_MIN ||
              downDp[y + 2 * diff][x][l - 1] == INT_MIN)
            break;
          int cur = topDp[y][x][l] + downDp[y + 2 * diff][x][l - 1];

          add(cur);
        }
      }
    }

    vector<int> answer;
    while (!pq.empty()) {
      answer.push_back(pq.top());
      pq.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};