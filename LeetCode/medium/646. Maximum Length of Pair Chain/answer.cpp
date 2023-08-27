#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & one pass
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int size = pairs.size();
    int answer = 1;

    sort(pairs.begin(), pairs.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int last = pairs[0][1];
    for (int i = 1; i < size; i++) {
      if (last < pairs[i][0]) {
        answer++;
        last = pairs[i][1];
      }
    }

    return answer;
  }
};

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int size = pairs.size();
    sort(pairs.begin(), pairs.end());

    vector<int> dp(size, 1);

    int answer = 1;
    for (int i = size - 1; i >= 0; i--) {
      for (int j = i + 1; j < size; j++) {
        if (pairs[i][1] < pairs[j][0]) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
      answer = max(answer, dp[i]);
    }
    return answer;
  }
};