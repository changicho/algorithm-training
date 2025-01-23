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

// use one pass
// time : O(R * C)
// space : O(R + C)
class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<int> rowCount(rows, 0);
    vector<int> colCount(cols, 0);

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;
        rowCount[y]++;
        colCount[x]++;
      }
    }

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;
        if (rowCount[y] > 1 || colCount[x] > 1) answer++;
      }
    }

    return answer;
  }
};