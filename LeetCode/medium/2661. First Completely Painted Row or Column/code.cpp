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

// use count
// time : O(R * C + N)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    vector<Axis> um(rows * cols + 1);
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        um[mat[y][x]] = {y, x};
      }
    }

    vector<int> rowCounts(rows, 0);
    vector<int> colCounts(cols, 0);

    int size = arr.size();
    for (int i = 0; i < size; i++) {
      Axis cur = um[arr[i]];

      rowCounts[cur.y]++;
      colCounts[cur.x]++;

      if (rowCounts[cur.y] == cols) return i;
      if (colCounts[cur.x] == rows) return i;
    }
    return -1;
  }
};