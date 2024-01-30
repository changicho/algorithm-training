#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use prefix sum
// time : O(R * C^2)
// space : O(R * C)
class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();

    vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        prefixSum[y + 1][x + 1] += prefixSum[y][x + 1] + prefixSum[y + 1][x] -
                                   prefixSum[y][x] + matrix[y][x];
      }
    }

    int answer = 0;

    for (int y1 = 0; y1 < rows; y1++) {
      for (int y2 = y1; y2 < rows; y2++) {
        for (int x1 = 0; x1 < cols; x1++) {
          for (int x2 = x1; x2 < cols; x2++) {
            int curSum = prefixSum[y2 + 1][x2 + 1] - prefixSum[y1][x2 + 1] -
                         prefixSum[y2 + 1][x1] + prefixSum[y1][x1];
            if (curSum == target) answer++;
          }
        }
      }
    }
    return answer;
  }
};

// use prefix sum (fix col)
// time : O(R * C^2)
// space : O(R * C)
class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    for (int y = 0; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        matrix[y][x] += matrix[y][x - 1];
      }
    }

    int answer = 0;

    // fix x1 ~ x2
    for (int x1 = 0; x1 < cols; x1++) {
      for (int x2 = x1; x2 < cols; x2++) {
        // sum, count
        unordered_map<int, int> count;
        count[0] = 1;

        int curSum = 0;
        for (int y = 0; y < rows; y++) {
          curSum += matrix[y][x2] - (x1 > 0 ? matrix[y][x1 - 1] : 0);

          if (count.find(curSum - target) != count.end()) {
            answer += count[curSum - target];
          }
          count[curSum]++;
        }
      }
    }
    return answer;
  }
};