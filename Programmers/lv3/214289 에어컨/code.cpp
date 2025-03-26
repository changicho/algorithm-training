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

const int LIMIT = 50;

int solution(int temperature, int t1, int t2, int a, int b,
             vector<int> onboard) {
  // while(!onboard.empty() && onboard.back() == 0){
  //     onboard.pop_back();
  // }

  int size = onboard.size();

  temperature += 10;
  t1 += 10;
  t2 += 10;

  vector<int> dp(LIMIT + 1, INT_MAX);

  dp[temperature] = 0;

  for (int day = 1; day < size; day++) {
    vector<int> newDp(LIMIT + 1, INT_MAX);

    bool hasHuman = onboard[day];
    int leftT = hasHuman ? t1 : 0;
    int rightT = hasHuman ? t2 : LIMIT;

    for (int t = leftT; t <= rightT; t++) {
      // turn off air conditioner case
      if (t <= temperature && t - 1 >= 0) {
        newDp[t] = min(newDp[t], dp[t - 1]);
      }
      if (t >= temperature && t + 1 <= LIMIT) {
        newDp[t] = min(newDp[t], dp[t + 1]);
      }
      if (t == temperature) {
        newDp[t] = min(newDp[t], dp[t]);
      }

      // turn on conditioner case
      if (t + 1 <= LIMIT && dp[t + 1] != INT_MAX)
        newDp[t] = min(newDp[t], dp[t + 1] + a);
      if (dp[t] != INT_MAX) newDp[t] = min(newDp[t], dp[t] + b);
      if (t - 1 >= 0 && dp[t - 1] != INT_MAX)
        newDp[t] = min(newDp[t], dp[t - 1] + a);
    }

    dp = newDp;
  }

  int answer = INT_MAX;
  for (int t = 0; t <= LIMIT; t++) {
    answer = min(answer, dp[t]);
  }

  return answer;
}
