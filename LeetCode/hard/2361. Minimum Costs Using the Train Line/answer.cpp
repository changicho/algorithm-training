#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<long long> minimumCosts(vector<int>& regular, vector<int>& express,
                                 int expressCost) {
    int size = regular.size();
    long long dp[100002][2];

    dp[0][0] = 0;
    dp[0][1] = expressCost;

    for (int i = 1; i <= size; i++) {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + regular[i - 1];
      dp[i][1] = min(dp[i][0] + expressCost, dp[i - 1][1] + express[i - 1]);
    }

    vector<long long> answer;
    for (int i = 1; i <= size; i++) {
      answer.push_back(min(dp[i][0], dp[i][1]));
    }
    return answer;
  }
};

// use dynamic programming (dynamic programming)
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<long long> minimumCosts(vector<int>& regular, vector<int>& express,
                                 int expressCost) {
    int size = regular.size();
    long long curRegular = 0, curExpress = expressCost;

    vector<long long> answer(size);
    for (int i = 1; i <= size; i++) {
      long long beforeRegular = curRegular, beforeExpress = curExpress;

      curRegular = min(beforeRegular, beforeExpress) + regular[i - 1];
      curExpress =
          min(curRegular + expressCost, beforeExpress + express[i - 1]);

      answer[i - 1] = min(curRegular, curExpress);
    }

    return answer;
  }
};