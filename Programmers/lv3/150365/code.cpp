#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct Status {
  Axis axis;
  string path;
};

char dirChars[4] = {'l', 'r', 'u', 'd'};
Axis dirs[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

string solution(int n, int m, int x, int y, int r, int c, int k) {
  vector<vector<string>> dp(n, vector<string>(m, "-"));

  Axis start = {x - 1, y - 1}, goal = {r - 1, c - 1};

  dp[start.y][start.x] = "";

  for (int step = 0; step < k; step++) {
    vector<vector<string>> newDp(n, vector<string>(m, "-"));

    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (dp[y][x] == "-") continue;

        for (int i = 0; i < 4; i++) {
          string nextPath = dp[y][x];
          nextPath += dirChars[i];

          Axis next = {y + dirs[i].y, x + dirs[i].x};

          if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;
          if (newDp[next.y][next.x] == "-") {
            newDp[next.y][next.x] = nextPath;
          } else {
            newDp[next.y][next.x] = min(newDp[next.y][next.x], nextPath);
          }
        }
      }
    }

    dp = newDp;
  }

  if (dp[goal.y][goal.x] == "-") {
    return "impossible";
  }

  return dp[goal.y][goal.x];
}