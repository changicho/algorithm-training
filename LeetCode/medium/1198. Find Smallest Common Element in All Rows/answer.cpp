#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  int smallestCommonElement(vector<vector<int>> &mat) {
    int rows = mat.size(), cols = mat.front().size();

    int counts[10001] = {
        0,
    };
    int answer = INT_MAX;
    for (vector<int> &row : mat) {
      for (int &num : row) {
        counts[num]++;

        if (counts[num] == rows) {
          answer = min(num, answer);
        }
      }
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};

// use binary search
// time : O(R * log_2(C))
// space : O(1)
class Solution {
 public:
  int smallestCommonElement(vector<vector<int>> &mat) {
    int rows = mat.size(), cols = mat[0].size();

    int answer = -1;
    for (int x = 0; x < cols && answer == -1; x++) {
      bool found = true;
      int target = mat[0][x];

      for (int y = 1; y < rows && found; y++) {
        int i =
            lower_bound(mat[y].begin(), mat[y].end(), target) - mat[y].begin();
        if (i == cols || mat[y][i] != target) {
          found = false;
          break;
        }
      }

      if (found) {
        answer = target;
      }
    }
    return answer;
  }
};