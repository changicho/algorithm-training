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

// use brute force
// time : O(R * C)
// space : O(1)
class Solution {
 private:
  bool isValid(int y, int x, vector<vector<int>>& grid) {
    int counts[16] = {
        0,
    };
    int rowSums[3] = {
        0,
    };
    int colSums[3] = {
        0,
    };

    int first = 0;
    int second = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        counts[grid[y + i][x + j]]++;
        rowSums[i] += grid[y + i][x + j];
        colSums[j] += grid[y + i][x + j];

        if (i == j) first += grid[y + i][x + j];
        if (i == 2 - j) second += grid[y + i][x + j];
      }
    }

    for (int num = 1; num <= 9; num++) {
      if (counts[num] != 1) return false;
    }

    if (first != second) return false;
    for (int i = 0; i < 2; i++) {
      if (rowSums[i] != rowSums[i + 1] || colSums[i] != colSums[i + 1])
        return false;
    }
    if (rowSums[0] != colSums[0] || rowSums[0] != first) return false;
    return true;
  }

 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    int answer = 0;
    for (int y = 0; y <= rows - 3; y++) {
      for (int x = 0; x <= cols - 3; x++) {
        if (isValid(y, x, grid)) answer++;
      }
    }

    return answer;
  }
};