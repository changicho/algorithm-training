#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// use greedy
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> counts;
    for (vector<int>& row : grid) {
      int count = 0;
      for (int x = cols - 1; x >= 0; x--) {
        if (row[x] == 0)
          count++;
        else
          break;
      }

      counts.push_back(count);
    }

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      bool isFind = false;
      for (int i = y; i < rows; i++) {
        if (counts[i] >= (cols - y - 1)) {
          for (int j = i; j > 0; j--) {
            swap(counts[j], counts[j - 1]);
          }
          answer += (i - y);
          isFind = true;
          break;
        }
      }

      if (!isFind) return -1;
    }
    return answer;
  }
};