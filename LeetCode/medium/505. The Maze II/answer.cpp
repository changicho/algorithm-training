#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(R * C * max(R, C))
// space : O(R * C)
class Solution {
  struct Status {
    int y, x, move = 0;
  };

  Status dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  bool isSafe(Status a, int rows, int cols) {
    return a.y >= 0 && a.y < rows && a.x >= 0 && a.x < cols;
  }

 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    int rows = maze.size(), cols = maze[0].size();

    int dp[101][101] = {
        0,
    };
    memset(dp, -1, sizeof(dp));

    queue<Status> q;
    q.push({start[0], start[1], 0});

    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      if (dp[cur.y][cur.x] != -1 && dp[cur.y][cur.x] <= cur.move) continue;
      dp[cur.y][cur.x] = cur.move;

      for (Status& dir : dirs) {
        Status next = cur;

        while (isSafe(next, rows, cols) && maze[next.y][next.x] == 0) {
          next.y += dir.y;
          next.x += dir.x;
        }

        next.y -= dir.y;
        next.x -= dir.x;

        int newMove = abs(next.y - cur.y) + abs(next.x - cur.x);

        q.push({next.y, next.x, cur.move + newMove});
      }
    }
    return dp[destination[0]][destination[1]];
  }
};

// use BFS
// time : O(R * C * max(R, C))
// space : O(R * C)
class Solution {
  struct Status {
    int y, x, move = 0;
  };

  Status dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  bool isSafe(Status a, int rows, int cols) {
    return a.y >= 0 && a.y < rows && a.x >= 0 && a.x < cols;
  }

 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    int rows = maze.size(), cols = maze[0].size();

    int dp[101][101] = {
        0,
    };
    memset(dp, -1, sizeof(dp));

    queue<Status> q;
    q.push({start[0], start[1], 0});
    dp[start[0]][start[1]] = 0;

    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      for (Status& dir : dirs) {
        Status next = cur;

        while (isSafe(next, rows, cols) && maze[next.y][next.x] == 0) {
          next.y += dir.y;
          next.x += dir.x;
        }

        next.y -= dir.y;
        next.x -= dir.x;

        int newMove = abs(next.y - cur.y) + abs(next.x - cur.x);

        if (dp[next.y][next.x] != -1 &&
            dp[next.y][next.x] <= cur.move + newMove)
          continue;

        dp[next.y][next.x] = cur.move + newMove;

        q.push({next.y, next.x, cur.move + newMove});
      }
    }
    return dp[destination[0]][destination[1]];
  }
};

// use dijkstra
// time : O(R * C * log_2(R * C))
// space : O(R * C)
class Solution {
  struct Status {
    int y, x, move = 0;

    bool operator<(const Status& a) const { return move > a.move; }
  };

  Status dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  bool isSafe(Status a, int rows, int cols) {
    return a.y >= 0 && a.y < rows && a.x >= 0 && a.x < cols;
  }

 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    int rows = maze.size(), cols = maze[0].size();

    int dp[101][101] = {
        0,
    };
    memset(dp, -1, sizeof(dp));

    priority_queue<Status> pq;
    pq.push({start[0], start[1], 0});
    dp[start[0]][start[1]] = 0;

    while (!pq.empty()) {
      Status cur = pq.top();
      pq.pop();

      for (Status& dir : dirs) {
        Status next = cur;

        while (isSafe(next, rows, cols) && maze[next.y][next.x] == 0) {
          next.y += dir.y;
          next.x += dir.x;
        }

        next.y -= dir.y;
        next.x -= dir.x;

        int newMove = abs(next.y - cur.y) + abs(next.x - cur.x);

        if (dp[next.y][next.x] != -1 &&
            dp[next.y][next.x] <= cur.move + newMove)
          continue;

        dp[next.y][next.x] = cur.move + newMove;

        pq.push({next.y, next.x, cur.move + newMove});
      }
    }
    return dp[destination[0]][destination[1]];
  }
};