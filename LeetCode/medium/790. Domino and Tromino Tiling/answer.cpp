#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numTilings(int n) {
    if (n <= 2) {
      return n;
    }

    long fully[n + 1];
    long partially[n + 1];

    fully[1] = 1L;
    fully[2] = 2L;
    partially[2] = 1L;

    for (int i = 3; i <= n; i++) {
      fully[i] = (fully[i - 1] + fully[i - 2] + 2 * partially[i - 1]) % MOD;
      partially[i] = (partially[i - 1] + fully[i - 2]) % MOD;
    }
    return int(fully[n]);
  }
};