#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(G * N)
// space : O(G * N)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int numMusicPlaylists(int n, int goal, int k) {
    long long dp[101][101] = {
        0,
    };

    dp[0][0] = 1;

    for (int len = 1; len <= goal; len++) {
      for (int songs = 1; songs <= min(len, n); songs++) {
        // The i-th song is a new song
        dp[len][songs] =
            dp[len - 1][songs - 1] * (n - songs + 1) % MOD;

        // The i-th song is a song we have played before
        if (songs > k) {
          dp[len][songs] += dp[len - 1][songs] * (songs - k);
          dp[len][songs] %= MOD;
        }
      }
    }

    return dp[goal][n];
  }
};