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

// use simulation
// time : O(N + M)
// space : O(M)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int calc(Axis &a) { return a.y * a.y + a.x * a.x; }

 public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    Axis cur = {0, 0};
    int dir = 0;

    int answer = 0;

    unordered_map<int, unordered_set<int>> um;
    for (vector<int> &o : obstacles) {
      int x = o[0], y = -o[1];

      um[y].insert(x);
    }

    for (int &c : commands) {
      if (c < 0) {
        // turn
        if (c == -1) {
          dir = (dir + 1) % 4;
        } else {
          dir = (dir - 1 + 4) % 4;
        }
      } else {
        Axis move = dirs[dir];
        for (int i = 0; i < c; i++) {
          Axis next = {cur.y + move.y, cur.x + move.x};

          if (um[next.y].count(next.x)) {
            break;
          }
          cur = next;
        }

        answer = max(answer, calc(cur));
      }
    }

    return answer;
  }
};