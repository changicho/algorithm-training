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

// math
// time : O(1)
// space : O(1)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

 public:
  int minBishopMoves(vector<int>& source, vector<int>& target) {
    Axis s = {source[0] - 1, source[1] - 1};
    Axis t = {target[0] - 1, target[1] - 1};

    if ((s.y + s.x) % 2 != (t.y + t.x) % 2) return -1;
    if (abs(s.y - t.y) == abs(s.x - t.x)) return 1;

    return 2;
  }
};

// BFS
// time : O(8^2 * 16)
// space : O(8^2)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

 public:
  int minBishopMoves(vector<int>& source, vector<int>& target) {
    bool dp[8][8] = {
        false,
    };
    Axis s = {source[0] - 1, source[1] - 1};
    Axis t = {target[0] - 1, target[1] - 1};

    if ((s.y + s.x) % 2 != (t.y + t.x) % 2) return -1;

    dp[s.y][s.x] = true;
    queue<Axis> q;
    q.push(s);

    int step = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Axis cur = q.front();
        q.pop();

        if (cur.y == t.y && cur.x == t.x) {
          return step;
        }

        for (Axis& d : dirs) {
          Axis next = {cur.y + d.y, cur.x + d.x};

          while (next.y >= 0 && next.y < 8 && next.x >= 0 && next.x < 8) {
            if (dp[next.y][next.x] == false) {
              q.push(next);
            }
            dp[next.y][next.x] = true;

            next.y += d.y;
            next.x += d.x;
          }
        }
      }
      step++;
    }
    return -1;
  }
};