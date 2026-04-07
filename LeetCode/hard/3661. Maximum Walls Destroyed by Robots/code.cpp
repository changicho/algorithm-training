#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

class Solution {
 private:
  struct Robot {
    int p;
    int d;
  };

 public:
  int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    int size = robots.size();
    vector<Robot> arr(size);

    for (int i = 0; i < size; i++) {
      arr[i].p = robots[i];
      arr[i].d = distance[i];
    }

    sort(walls.begin(), walls.end());
    sort(arr.begin(), arr.end(),
         [](const Robot& a, const Robot& b) { return a.p < b.p; });

    arr.push_back({(int)1e9, 0});

    function<int(int, int)> getCount = [&](int left, int right) {
      if (left > right) return 0;
      auto it1 = upper_bound(walls.begin(), walls.end(), right);
      auto it2 = lower_bound(walls.begin(), walls.end(), left);
      int res = it1 - it2;
      return res;
    };

    // dp[index][direction]
    // 0 : left, 1 : right
    vector<vector<int>> dp(size, vector<int>(2));

    // base case
    dp[0][0] = getCount(arr[0].p - arr[0].d, arr[0].p);
    if (size > 1) {
      dp[0][1] = getCount(arr[0].p, min(arr[1].p - 1, arr[0].p + arr[0].d));
    } else {
      dp[0][1] = getCount(arr[0].p, arr[0].p + arr[0].d);
    }

    for (int i = 1; i < size; i++) {
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) +
                 getCount(arr[i].p, min(arr[i + 1].p - 1, arr[i].p + arr[i].d));

      int curLeft = max(arr[i].p - arr[i].d, arr[i - 1].p + 1);
      int beforeRight = min(arr[i - 1].p + arr[i - 1].d, arr[i].p - 1);

      int left2left = dp[i - 1][0] + getCount(curLeft, arr[i].p);

      int right2left = dp[i - 1][1] + getCount(curLeft, arr[i].p) -
                       getCount(curLeft, beforeRight);

      dp[i][0] = max(right2left, left2left);
    }
    return max(dp[size - 1][0], dp[size - 1][1]);
  }
};