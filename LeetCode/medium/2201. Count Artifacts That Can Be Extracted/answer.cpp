#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map
// time : O(A * N^2)
// space : O(N^2)
class Solution {
 private:
  int convert(int r, int c) { return r * 10000 + c; }

 public:
  int digArtifacts(int n, vector<vector<int>>& artifacts,
                   vector<vector<int>>& dig) {
    // hash map, axis to num
    // hash map, num to axis
    unordered_map<int, int> axis2Color;
    unordered_map<int, unordered_set<int>> color2Axis;

    // O(A)
    for (vector<int>& a : artifacts) {
      int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];

      int color = color2Axis.size() + 1;
      // O(N^2)
      for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
          int axis = convert(r, c);

          axis2Color[axis] = color;
          color2Axis[color].insert(axis);
        }
      }
    }

    int answer = 0;
    // O(D)
    for (vector<int>& d : dig) {
      int r = d[0], c = d[1];

      int axis = convert(r, c);
      int color = axis2Color[axis];

      if (color == 0) continue;

      color2Axis[color].erase(axis);
      if (color2Axis[color].size() == 0) {
        answer++;
      }
    }

    return answer;
  }
};

// use dig first
// time : O(A * N^2)
// space : O(N^2)
class Solution {
 public:
  int digArtifacts(int n, vector<vector<int>>& artifacts,
                   vector<vector<int>>& dig) {
    // O(N^2)
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // O(D)
    for (vector<int>& d : dig) {
      visited[d[0]][d[1]] = 1;
    }

    int answer = 0;
    // O(N)
    for (vector<int>& a : artifacts) {
      int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];
      bool canFind = true;

      // O(N^2)
      for (int i = r1; i <= r2 && canFind; i++) {
        for (int j = c1; j <= c2 && canFind; j++) {
          if (visited[i][j]) continue;

          canFind = false;
          break;
        }
      }

      if (canFind) {
        answer++;
      }
    }

    return answer;
  }
};

// use prefix sum
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int digArtifacts(int n, vector<vector<int>>& artifacts,
                   vector<vector<int>>& dig) {
    vector<vector<int>> visited(n, vector<int>(n, 1));
    // O(D)
    for (vector<int>& d : dig) {
      visited[d[0]][d[1]] = 0;
    }
    // O(N^2)
    int preSum[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
      preSum[i][0] = 0;
      preSum[0][i] = 0;
    }

    // O(N^2)
    for (int y = 1; y <= n; y++) {
      for (int x = 1; x <= n; x++) {
        preSum[y][x] = preSum[y - 1][x] + preSum[y][x - 1] -
                       preSum[y - 1][x - 1] + visited[y - 1][x - 1];
      }
    }

    int answer = 0;
    // O(A)
    for (vector<int>& a : artifacts) {
      int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];

      int sum = preSum[r2 + 1][c2 + 1] - preSum[r1][c2 + 1] -
                preSum[r2 + 1][c1] + preSum[r1][c1];

      if (sum == 0) answer++;
    }

    return answer;
  }
};