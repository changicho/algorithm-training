#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int size = jobDifficulty.size();
    // dp[index][split] : minimum cost when range(0 ~ index), split
    vector<vector<long>> dp(size, vector<long>(d + 1, INT_MAX));
    // maximum[from][to] : maximum value of from ~ do
    vector<vector<int>> maximum(size, vector<int>(size, 0));

    // initialize maximum
    for (int i = 0; i < size; i++) {
      maximum[i][i] = jobDifficulty[i];
    }
    for (int from = 0; from < size; from++) {
      for (int to = from + 1; to < size; to++) {
        maximum[from][to] = max(maximum[from][to - 1], jobDifficulty[to]);
      }
    }

    // initialize dp
    for (int i = 0; i < size; i++) {
      dp[i][1] = maximum[0][i];
    }

    for (int split = 2; split <= d; split++) {
      for (int index = 0; index < size; index++) {
        for (int before = 0; before < index; before++) {
          long curCost = dp[before][split - 1] + maximum[before + 1][index];

          dp[index][split] = min(curCost, dp[index][split]);
        }
      }
    }

    if ((int)dp[size - 1][d] == INT_MAX) return -1;
    return (int)dp[size - 1][d];
  }
};
