#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * W)
// space : O(N)
class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int size = books.size();

    vector<int> dp(size, 0);

    for (int i = 0; i < size; i++) {
      int width = books[i][0], height = books[i][1];
      dp[i] = (i > 0 ? dp[i - 1] : 0) + height;

      for (int j = i - 1; j >= 0; j--) {
        width += books[j][0];

        if (width > shelfWidth) {
          break;
        }

        height = max(height, books[j][1]);
        dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + height);
      }
    }

    return dp[size - 1];
  }
};