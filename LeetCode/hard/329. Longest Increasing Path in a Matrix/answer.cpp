#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use DFS with memoization

class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> dp;

  int recursive(vector<vector<int>>& matrix, Axis& axis) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    int maxLength = 0;
    for (Axis& dir : dirs) {
      Axis next = {dir.y + axis.y, dir.x + axis.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (matrix[next.y][next.x] <= matrix[axis.y][axis.x]) continue;
      if (dp[next.y][next.x] != 1) {
        maxLength = max(maxLength, dp[next.y][next.x]);
        continue;
      }

      int curLength = recursive(matrix, next);
      maxLength = max(maxLength, curLength);
    }

    return dp[axis.y][axis.x] = maxLength + 1;
  }

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    dp.resize(rows, vector<int>(cols, 1));

    int answer = 1;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        Axis start = {y, x};
        int curAnswer = recursive(matrix, start);
        answer = max(answer, curAnswer);
      }
    }

    return answer;
  }
};

// use greedy algorithm

class Solution {
 private:
  struct Axis {
    int y, x;
  };

  struct Status {
    Axis axis;
    int count;

    bool operator<(const Status& b) const { return count > b.count; }
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    vector<vector<int>> dp(rows, vector<int>(cols, 1));

    priority_queue<Status> pq;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        pq.push({{y, x}, 1});
      }
    }

    while (!pq.empty()) {
      Status cur = pq.top();
      pq.pop();

      Axis axis = cur.axis;

      for (Axis& dir : dirs) {
        Axis next = {dir.y + axis.y, dir.x + axis.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (matrix[next.y][next.x] <= matrix[axis.y][axis.x]) continue;
        if (dp[next.y][next.x] >= dp[axis.y][axis.x] + 1) continue;

        dp[next.y][next.x] = dp[axis.y][axis.x] + 1;
        pq.push({next, dp[next.y][next.x]});
      }
    }

    int answer = 1;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer = max(answer, dp[y][x]);
      }
    }
    return answer;
  }
};