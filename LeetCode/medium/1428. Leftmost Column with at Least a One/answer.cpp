#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BinaryMatrix {
 public:
  int get(int row, int col);
  vector<int> dimensions();
};

// use binary search

class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> dimensions = binaryMatrix.dimensions();
    int rows = dimensions.front();
    int cols = dimensions.back();

    int answer = cols;
    for (int row = 0; row < rows; row++) {
      int left = 0, right = cols - 1;
      int target = -1;

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (binaryMatrix.get(row, mid) == 1) {
          right = mid - 1;
          answer = min(mid, answer);
        } else {
          left = mid + 1;
        }
      }
    }

    if (answer == cols) return -1;
    return answer;
  }
};

// use move only left and down

class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> dimensions = binaryMatrix.dimensions();
    int rows = dimensions.front();
    int cols = dimensions.back();

    int currentRow = 0;
    int currentCol = cols - 1;

    while (currentRow < rows && currentCol >= 0) {
      if (binaryMatrix.get(currentRow, currentCol) == 0) {
        currentRow++;
      } else {
        currentCol--;
      }
    }

    if (currentCol == cols - 1) return -1;
    return currentCol + 1;
  }
};