#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^3)
// space : O(N)
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int size = grid.size();

    vector<int> dp(size, INT_MAX);

    for (int x = 0; x < size; x++) {
      dp[x] = grid[0][x];
    }
    for (int y = 1; y < size; y++) {
      vector<int> newDp(size, INT_MAX);
      for (int x = 0; x < size; x++) {
        for (int before = 0; before < size; before++) {
          if (x == before) continue;

          newDp[x] = min(newDp[x], dp[before] + grid[y][x]);
        }
      }

      dp = newDp;
    }

    int answer = INT_MAX;
    for (int x = 0; x < size; x++) {
      answer = min(answer, dp[x]);
    }
    return answer;
  }
};

// use two minimum
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  vector<int> findTwoMinimum(vector<int>& row) {
    int first = INT_MAX, second = INT_MAX;
    for (int& num : row) {
      if (num < first) {
        // second = exchange(first, x);
        second = first;
        first = num;
      } else if (num < second)
        second = num;
    }
    return {first, second};
  }

 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int size = grid.size();

    for (int y = 1; y < size; y++) {
      vector<int> minimums = findTwoMinimum(grid[y - 1]);

      for (int x = 0; x < size; x++) {
        if (grid[y - 1][x] == minimums[0]) {
          grid[y][x] += minimums[1];
        } else {
          grid[y][x] += minimums[0];
        }
      }
    }

    int answer = INT_MAX;
    for (int& num : grid[size - 1]) {
      answer = min(answer, num);
    }
    return answer;
  }
};

// use two minimum (space optimized)
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  struct Minimum {
    int first, second;
    int firstI, secondI;
  };

 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int size = grid.size();

    Minimum before = {INT_MAX, INT_MAX, -1, -1};
    for (int x = 0; x < size; x++) {
      if (grid[0][x] < before.first) {
        before.second = before.first;
        before.secondI = before.firstI;

        before.first = grid[0][x];
        before.firstI = x;
      } else if (grid[0][x] < before.second) {
        before.second = grid[0][x];
        before.secondI = x;
      }
    }

    for (int y = 1; y < size; y++) {
      Minimum cur = {INT_MAX, INT_MAX, -1, -1};

      for (int x = 0; x < size; x++) {
        int newCost =
            (x == before.firstI ? before.second : before.first) + grid[y][x];

        if (newCost < cur.first) {
          cur.second = cur.first;
          cur.secondI = cur.firstI;

          cur.first = newCost;
          cur.firstI = x;
        } else if (newCost < cur.second) {
          cur.second = newCost;
          cur.secondI = x;
        }
      }

      before = cur;
    }

    return before.first;
  }
};