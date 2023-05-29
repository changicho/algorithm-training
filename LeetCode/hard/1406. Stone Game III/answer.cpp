#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 private:
  int size;
  long dp[2][50001];
  vector<int> stoneValue;

  int recursive(bool isAlice, int index) {
    if (index == size) {
      return 0;
    }

    if (dp[isAlice][index] != INT_MIN) {
      return dp[isAlice][index];
    }

    int res = isAlice ? INT_MIN : INT_MAX;
    int selected = 0;
    for (int next = index; next < size && (next - index + 1) <= 3; next++) {
      selected += stoneValue[next];

      if (isAlice) {
        res = max(res, selected + recursive(false, next + 1));
      } else {
        res = min(res, recursive(true, next + 1));
      }
    }
    return dp[isAlice][index] = res;
  };

 public:
  string stoneGameIII(vector<int>& stoneValue) {
    this->stoneValue = stoneValue;
    this->size = stoneValue.size();

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 50001; j++) {
        dp[i][j] = INT_MIN;
      }
    }
    recursive(true, 0);

    long sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);

    long aliceScore = dp[true][0];
    long bobScore = sum - aliceScore;

    if (aliceScore > bobScore) {
      return "Alice";
    } else if (aliceScore < bobScore) {
      return "Bob";
    } else {
      return "Tie";
    }
  }
};