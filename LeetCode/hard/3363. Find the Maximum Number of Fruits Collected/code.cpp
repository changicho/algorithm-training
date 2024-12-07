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

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    int size = fruits.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      answer += fruits[i][i];
      fruits[i][i] = 0;
    }

    vector<vector<int>> dpU2D(size, vector<int>(size, -1));
    dpU2D[0][size - 1] = fruits[0][size - 1];
    fruits[0][size - 1] = 0;

    for (int y = 0; y < size - 1; y++) {
      for (int x = 0; x < size; x++) {
        if (dpU2D[y][x] == -1) continue;

        for (int d = -1; d <= 1; d++) {
          if (x + d < 0 || x + d >= size) continue;
          dpU2D[y + 1][x + d] =
              max(dpU2D[y + 1][x + d], dpU2D[y][x] + fruits[y + 1][x + d]);
        }
      }
    }

    vector<vector<int>> dpL2R(size, vector<int>(size, -1));
    dpL2R[size - 1][0] = fruits[size - 1][0];
    fruits[size - 1][0] = 0;

    for (int x = 0; x < size - 1; x++) {
      for (int y = 0; y < size; y++) {
        if (dpL2R[y][x] == -1) continue;

        for (int d = -1; d <= 1; d++) {
          if (y + d < 0 || y + d >= size) continue;
          dpL2R[y + d][x + 1] =
              max(dpL2R[y + d][x + 1], dpL2R[y][x] + fruits[y + d][x + 1]);
        }
      }
    }

    return answer + dpU2D[size - 1][size - 1] + dpL2R[size - 1][size - 1];
  }
};