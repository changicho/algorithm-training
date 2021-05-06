#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// use visited array

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int dirIdx = 0;
    Axis dir = dirs[dirIdx];
    Axis cur = {0, 0};

    vector<int> answer;
    vector<vector<bool>> visited(row, vector<bool>(col));

    int limit = row * col;
    for (int i = 0; i < limit; i++) {
      answer.push_back(matrix[cur.y][cur.x]);
      visited[cur.y][cur.x] = true;

      Axis next = cur;
      next.y += dir.y;
      next.x += dir.x;

      if (0 > next.y || row <= next.y || 0 > next.x || col <= next.x || visited[next.y][next.x]) {
        dirIdx = (dirIdx + 1) % 4;
        dir = dirs[dirIdx];

        next = cur;
        next.y += dir.y;
        next.x += dir.x;
      }

      cur = next;
    }

    return answer;
  }
};

// not use visited array

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    Axis cur = {0, -1};

    vector<int> answer;

    int limit = row * col;
    while (answer.size() < limit) {
      for (int i = 0; i < col; i++) {
        cur.x += 1;
        answer.push_back(matrix[cur.y][cur.x]);
      }
      if (answer.size() == limit) break;

      for (int i = 0; i < row - 1; i++) {
        cur.y += 1;
        answer.push_back(matrix[cur.y][cur.x]);
      }
      if (answer.size() == limit) break;

      for (int i = 0; i < col - 1; i++) {
        cur.x -= 1;
        answer.push_back(matrix[cur.y][cur.x]);
      }
      if (answer.size() == limit) break;

      for (int i = 0; i < row - 2; i++) {
        cur.y -= 1;
        answer.push_back(matrix[cur.y][cur.x]);
      }
      if (answer.size() == limit) break;

      col -= 2;
      row -= 2;
    }

    return answer;
  }
};