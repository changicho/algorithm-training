#include <algorithm>
#include <climits>
#include <cmath>
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

// use dynamic programming
// time : O(1)
// space : O(1)
class Solution {
 private:
  int mids[9][9];

  void calcMids() {
    vector<int> nums = {0, 2, 6, 8};

    for (int &from : nums) {
      for (int &to : nums) {
        if (from == to) continue;
        int mid = (from + to) / 2;

        mids[from][to] = mid;
        mids[to][from] = mid;
      }
    }
    mids[1][7] = mids[7][1] = 4;
    mids[3][5] = mids[5][3] = 4;
  }

  bool checkPath(int from, int to, int bit) {
    int mid = mids[from][to];

    if (mid == 0) {
      return true;
    }

    if (bit & (1 << mid)) return true;
    return false;
  }

 public:
  int numberOfPatterns(int m, int n) {
    calcMids();

    const int BIT_SIZE = 1 << 9;
    // [step][axis][bit]
    int dp[10][9][BIT_SIZE] = {
        0,
    };

    for (int a = 0; a < 9; a++) {
      dp[1][a][1 << a] = 1;
    }

    int answer = 0;
    if (m == 1) answer += 9;

    for (int step = 2; step <= 9; step++) {
      for (int from = 0; from < 9; from++) {
        for (int bit = 0; bit < BIT_SIZE; bit++) {
          for (int to = 0; to < 9; to++) {
            if (bit & (1 << to)) continue;

            if (!checkPath(from, to, bit)) continue;
            int newBit = bit | (1 << to);
            dp[step][to][newBit] += dp[step - 1][from][bit];

            if (m <= step && step <= n) {
              answer += dp[step - 1][from][bit];
            }
          }
        }
      }
    }

    return answer;
  }
};