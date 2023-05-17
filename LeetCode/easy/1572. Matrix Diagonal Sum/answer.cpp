#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;

    int size = mat.size();
    for (int y = 0; y < size; y++) {
      int leftX = y, rightX = size - 1 - leftX;

      sum += mat[y][leftX];
      if (leftX != rightX) {
        sum += mat[y][rightX];
      }
    }

    return sum;
  }
};