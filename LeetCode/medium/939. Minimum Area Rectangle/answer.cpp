#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map & yToX, xToY
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    // O(N)
    unordered_map<int, unordered_map<int, bool>> hashP;
    // O(N)
    unordered_map<int, unordered_set<int>> yToX, xToY;

    int answer = INT_MAX;

    // O(N)
    for (vector<int>& point : points) {
      int y1 = point[0], x1 = point[1];

      // O(sqrt(N))
      for (int x2 : yToX[y1]) {
        int xDiff = x1 - x2;
        if (xDiff == 0) continue;

        // O(sqrt(N))
        for (int y2 : xToY[x2]) {
          int yDiff = y1 - y2;
          if (yDiff == 0) continue;

          if (hashP[y2][x1]) {
            answer = min(answer, abs(xDiff * yDiff));
          }
        }
      }

      yToX[y1].emplace(x1);
      xToY[x1].emplace(y1);
      hashP[y1][x1] = true;
    }

    return answer == INT_MAX ? 0 : answer;
  }
};

// use hash map pair set
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  struct Hash {
    size_t operator()(const pair<int, int>& x) const {
      return hash<long long>()(((long long)x.first) ^
                               (((long long)x.second) << 32));
    }
  };

 public:
  int minAreaRect(vector<vector<int>>& points) {
    // O(N)
    unordered_set<pair<int, int>, Hash> hashP;

    int answer = INT_MAX;

    // O(N)
    for (const vector<int>& p : points) {
      int x1 = p[0], y1 = p[1];

      // O(N)
      for (auto [x2, y2] : hashP) {
        if (x2 == x1 || y2 == y1) continue;

        if (hashP.count({x1, y2}) && hashP.count({x2, y1})) {
          answer = min(answer, abs((x1 - x2) * (y1 - y2)));
        }
      }

      hashP.emplace(x1, y1);  // insert
    }

    return answer == INT_MAX ? 0 : answer;
  }
};

// use hash map long long
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  const long long MOD = 100000;

 public:
  int minAreaRect(vector<vector<int>>& points) {
    // O(N)
    unordered_set<long long> hashP;

    int answer = INT_MAX;

    // O(N)
    for (const vector<int>& p : points) {
      int x1 = p[0], y1 = p[1];

      // O(N)
      for (long long cur : hashP) {
        int x2 = cur / MOD;
        int y2 = cur % MOD;

        if (x2 == x1 || y2 == y1) continue;

        if (hashP.count(x1 * MOD + y2) && hashP.count(x2 * MOD + y1)) {
          answer = min(answer, abs((x1 - x2) * (y1 - y2)));
        }
      }

      hashP.emplace(x1 * MOD + y1);  // insert
    }

    return answer == INT_MAX ? 0 : answer;
  }
};