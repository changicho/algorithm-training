#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^4)
// space : O(1)
class Solution {
 private:
  int countOverlap(int y, int x, vector<vector<int>>& img1,
                   vector<vector<int>>& img2) {
    int rows = img1.size(), cols = img1.front().size();
    int count = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int cur = 0;
        if (0 <= y + i && y + i < rows && 0 <= x + j && x + j < cols)
          cur = img2[y + i][x + j];

        if (cur == 1 && img1[i][j] == cur) {
          count++;
        }
      }
    }
    return count;
  }

 public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int rows = img1.size(), cols = img1.front().size();

    int answer = 0;
    for (int y = -rows + 1; y < rows; y++) {
      for (int x = -cols + 1; x < cols; x++) {
        int cur = countOverlap(y, x, img1, img2);
        answer = max(answer, cur);
      }
    }
    return answer;
  }
};