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

// prefix suffix
// time : O(RC)
// space : O(1)
class Solution {
 public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    const int MOD = 12345;

    int rows = grid.size(), cols = grid[0].size();

    long long prefix = 1;
    long long suffix = 1;

    vector<vector<int>> answer(rows, vector<int>(cols));
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer[y][x] = prefix;
        prefix *= grid[y][x];
        prefix %= MOD;
      }
    }

    for (int y = rows - 1; y >= 0; y--) {
      for (int x = cols - 1; x >= 0; x--) {
        answer[y][x] *= suffix;
        answer[y][x] %= MOD;
        suffix *= grid[y][x];
        suffix %= MOD;
      }
    }
    return answer;
  }
};