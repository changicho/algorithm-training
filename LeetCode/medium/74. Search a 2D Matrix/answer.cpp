#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search O(N * log_2(M))

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    int target_row = -1;
    for (int y = 0; y < rows; y++) {
      if (matrix[y].front() <= target && target <= matrix[y].back()) {
        target_row = y;
        break;
      }
    }

    if (target_row == -1) return false;

    if (upper_bound(matrix[target_row].begin(), matrix[target_row].end(), target) - lower_bound(matrix[target_row].begin(), matrix[target_row].end(), target) >= 1) return true;

    return false;
  }
};

// use binary search O(log_2(M * M))

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    int left = 0;
    int right = cols * rows - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      int y = mid / cols;
      int x = mid % cols;

      if (matrix[y][x] == target) {
        return true;
      } else if (matrix[y][x] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }
};

// use move axis

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;

    int rows = matrix.size();
    int cols = matrix.front().size();
    int y = 0, x = cols - 1;

    while (y < rows && x >= 0) {
      if (matrix[y][x] == target) {
        return true;
      } else if (matrix[y][x] > target) {
        x--;
      } else if (matrix[y][x] < target) {
        y++;
      }
    }

    return false;
  }
};