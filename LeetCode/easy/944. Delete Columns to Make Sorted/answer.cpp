#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use pass
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int answer = 0;

    int rows = strs.size(), cols = strs.front().size();

    for (int x = 0; x < cols; x++) {
      bool isSorted = true;
      for (int y = 0; y < rows - 1; y++) {
        if (strs[y][x] > strs[y + 1][x]) {
          isSorted = false;
          break;
        }
      }

      if (!isSorted) answer++;
    }

    return answer;
  }
};