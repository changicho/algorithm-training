#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use memoization
// time : O(N^3)
// space : O(N^2)
class Solution {
 private:
  int size;
  int dp[2][101][101];
  vector<int> piles;

  int recursive(bool isBob, int index, int m) {
    if (index == size) {
      return 0;
    }

    if (dp[isBob][index][m] != -1) {
      return dp[isBob][index][m];
    }

    int res = isBob ? INT_MAX : -1;
    int selected = 0;
    for (int next = index; next < size && (next - index + 1) <= 2 * m; next++) {
      selected += piles[next];

      int nextM = max(m, (next - index + 1));

      if (!isBob) {
        res = max(res, selected + recursive(true, next + 1, nextM));
      } else {
        res = min(res, recursive(false, next + 1, nextM));
      }
    }

    return dp[isBob][index][m] = res;
  };

 public:
  int stoneGameII(vector<int>& piles) {
    this->size = piles.size();
    this->piles = piles;

    memset(dp, -1, sizeof(dp));

    int answer = dp[false][0][1];
    return answer;
  }
};