#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2 * F)
// space : O(N * F)
class Solution {
 private:
  int MOD = 1e9 + 7;

 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int size = locations.size();
    // dp[city][fuel];
    // the number of possible routes starting from the city with fuel
    int dp[101][201] = {
        0,
    };

    for (int f = 0; f <= fuel; f++) {
      dp[finish][f] = 1;
    }

    for (int f = 0; f <= fuel; f++) {
      for (int from = 0; from < size; from++) {
        for (int to = 0; to < size; to++) {
          if (to == from) continue;

          if (abs(locations[from] - locations[to]) <= f) {
            int remainFuel = f - abs(locations[from] - locations[to]);
            dp[from][f] = (dp[from][f] + dp[to][remainFuel]) % MOD;
          }
        }
      }
    }

    return dp[start][fuel];
  }
};