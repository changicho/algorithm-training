#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(R * log_2(C))
// space : O(1)
class Solution {
 private:
  int getMinusCount(vector<int> &row) {
    int left = 0, right = row.size();
    int target = right;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (row[mid] < 0) {
        // pick left
        right = mid;
        target = mid;
      } else {
        // pick right
        left = mid + 1;
      }
    }

    return row.size() - target;
  }

 public:
  int countNegatives(vector<vector<int>> &grid) {
    int count = 0;

    for (vector<int> &row : grid) {
      count += getMinusCount(row);
    }

    return count;
  }
};

// use row col traverse
// time : O(R + C)
// space : O(1)
class Solution {
 public:
  int countNegatives(vector<vector<int>> &grid) {
    int cols = grid.front().size();
    int count = 0;
    int rI = cols - 1;

    for (vector<int> &row : grid) {
      while (rI >= 0 && row[rI] < 0) {
        rI--;
      }
      count += (cols - (rI + 1));
    }
    return count;
  }
};