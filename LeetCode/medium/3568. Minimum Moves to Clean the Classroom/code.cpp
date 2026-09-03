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

using ll = long long;

// bitmask memoization BFS
// time : O(RC * 2^L)
// space : O(RC * 2^L)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  struct Status {
    Axis a;
    int e;
    int remain = 0;
    int bit = 0;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int minMoves(vector<string>& classroom, int energy) {
    int rows = classroom.size(), cols = classroom[0].size();
    int dp[21][21][1024] = {
        0,
    };
    memset(dp, -1, sizeof(dp));

    Axis start = {-1, -1};
    int indexes[21][21] = {
        0,
    };

    int targetIndex = 0;
    int target = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (classroom[y][x] == 'S') {
          start = {y, x};
        } else if (classroom[y][x] == 'L') {
          target++;

          indexes[y][x] = targetIndex;
          targetIndex++;
        }
      }
    }

    if (start.y == -1) return -1;

    int answer = INT_MAX;
    queue<Status> q;
    q.push({start, energy, target, 0});
    dp[start.y][start.x][0] = energy;
    int step = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Status cur = q.front();
        q.pop();

        Axis a = cur.a;
        int e = cur.e;
        int remain = cur.remain;
        int bit = cur.bit;

        if (cur.remain == 0) {
          return step;
        }

        if (e == 0) continue;

        for (Axis& d : dirs) {
          Axis next = {a.y + d.y, a.x + d.x};
          int nextE = e - 1;
          int nextRemain = remain;
          int nextBit = bit;

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;

          if (classroom[next.y][next.x] == 'X') {
            continue;
          } else if (classroom[next.y][next.x] == 'L') {
            if ((nextBit & (1 << (indexes[next.y][next.x]))) == 0) {
              nextRemain--;
              nextBit |= 1 << (indexes[next.y][next.x]);
            }
          } else if (classroom[next.y][next.x] == 'R') {
            nextE = energy;
          }

          if (nextE < 0) continue;
          if (dp[next.y][next.x][nextBit] >= nextE) continue;
          dp[next.y][next.x][nextBit] = nextE;

          q.push({next, nextE, nextRemain, nextBit});
        }
      }

      step++;
    }

    return -1;
  }
};