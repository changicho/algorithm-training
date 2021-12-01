#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int size = stations.size();
    // dp[i] : maximum distance when visit i'th station
    vector<long long> dp(size + 1, 0);
    dp[0] = startFuel;

    for (int i = 0; i < size; i++) {
      vector<int>& station = stations[i];

      // we update from maximum index
      // if we update count + 1, it will effect when update next dp
      // so we use temp vector of current dp
      for (int cur = i; cur >= 0; cur--) {
        // we can visit current station use count'th stop
        if (dp[cur] >= station[0]) {
          long long newLength = dp[cur] + station[1];

          dp[cur + 1] = max(dp[cur + 1], newLength);
        }
      }
    }

    // find minimum count to reach target
    int answer = -1;
    for (int i = 0; i < dp.size(); i++) {
      if (dp[i] >= target) {
        answer = i;
        break;
      }
    }
    return answer;
  }
};

// use dp

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int size = stations.size();
    vector<long long> dp(size + 1, 0);
    dp[0] = startFuel;

    for (vector<int>& station : stations) {
      int position = station[0];
      long long fuel = station[1];

      // if we update count + 1, it will effect when update next dp
      // so we use temp vector of current dp
      vector<long long> nextDp = dp;
      // update next dp
      for (int cur = 0; cur < size; cur++) {
        if (dp[cur] >= position) {
          long long newLength = dp[cur] + fuel;

          nextDp[cur + 1] = max(dp[cur + 1], newLength);
        }
      }
      dp = nextDp;
    }

    int answer = -1;
    for (int i = 0; i < dp.size(); i++) {
      if (dp[i] >= target) {
        answer = i;
        break;
      }
    }
    return answer;
  }
};

// use heap

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int size = stations.size();
    // push visit possible station's fuel
    priority_queue<int> pq;

    int maximumDistance = startFuel;
    int stopCount = 0;
    int index = 0;

    while (maximumDistance < target) {
      // visit posssible station of current position
      while (index < size && stations[index][0] <= maximumDistance) {
        pq.push(stations[index][1]);
        index++;
      }

      // if there are no station to visit
      if (pq.empty()) return -1;

      maximumDistance += pq.top();
      pq.pop();
      stopCount++;
    }

    return stopCount;
  }
};