#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(R * C * K)
// space : O(R * C * K)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[8] = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                  {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

 public:
  double knightProbability(int n, int k, int row, int column) {
    double dp[26][26][101] = {
        0,
    };

    dp[row][column][0] = 1.0;

    for (int step = 1; step <= k; step++) {
      for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
          if (dp[y][x][step - 1] == 0) continue;

          Axis cur = {y, x};
          for (Axis &dir : dirs) {
            Axis next = {cur.y + dir.y, cur.x + dir.x};

            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
              continue;
            dp[next.y][next.x][step] += dp[cur.y][cur.x][step - 1] / 8.0;
          }
        }
      }
    }

    double answer = 0;
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        answer += dp[y][x][k];
      }
    }
    return answer;
  }
};

// use dynamic programming
// time : O(R * C * K)
// space : O(R * C * K)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[8] = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                  {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

 public:
  double knightProbability(int n, int k, int row, int column) {
    double dp[26][26][101] = {
        0,
    };

    dp[row][column][0] = 1.0;

    queue<Axis> q;
    q.push({row, column});

    for (int step = 1; step <= k; step++) {
      int size = q.size();

      while (size--) {
        Axis cur = q.front();
        q.pop();

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) continue;

          if (dp[next.y][next.x][step] == 0.0) {
            q.push(next);
          }
          dp[next.y][next.x][step] += dp[cur.y][cur.x][step - 1] / 8;
        }
      }
    }

    double answer = 0;
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        answer += dp[y][x][k];
      }
    }
    return answer;
  }
};