#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math
// time : O(log_2(N))
// space : O(1)
class Solution {
 private:
  const int MOD = 1e9 + 7;

  long pow(long x, long n) {
    long result = 1, p = x % MOD;

    while (n) {
      if (n % 2 == 1) {
        result = (result * p) % MOD;
      }
      p = (p * p) % MOD;
      n /= 2;
    }
    return result;
  }

 public:
  int stringCount(int n) {
    long long count = 0;

    count += pow(26, n);
    count %= MOD;

    count -= (n + 75) * pow(25, n - 1);
    count %= MOD;

    count += (2 * n + 72) * pow(24, n - 1);
    count %= MOD;

    count -= (n + 23) * pow(23, n - 1);
    count %= MOD;

    count += MOD;
    count %= MOD;

    return count;
  }
};

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 private:
  long long MOD = 1e9 + 7;

  long long dp[100001][3][2][2] = {
      0,
  };

  long long find(int index, int n, int e, int l, int t) {
    if (index == n) {
      if (e >= 2 && l >= 1 && t >= 1) {
        return 1;
      } else {
        return 0;
      }
    }

    if (dp[index][e][l][t] != -1) return dp[index][e][l][t];

    long long pick = 0;

    for (int i = 0; i < 26; i++) {
      if (i == 4 && e < 2) {
        pick = (pick + find(index + 1, n, e + 1, l, t)) % MOD;
      }

      else if (i == 11 && l < 1) {
        pick = (pick + find(index + 1, n, e, l + 1, t)) % MOD;
      } else if (i == 19 && t < 1) {
        pick = (pick + find(index + 1, n, e, l, t + 1)) % MOD;
      } else {
        pick = (pick + find(index + 1, n, e, l, t)) % MOD;
      }
    }

    return dp[index][e][l][t] = pick;
  }

 public:
  int stringCount(int n) {
    memset(dp, -1, sizeof(dp));
    return (int)(find(0, n, 0, 0, 0) % MOD);
  }
};