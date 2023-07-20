#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(M!/(M-N)!)
// space : O(N + M)
class Solution {
 private:
  vector<vector<int>> workers;
  vector<vector<int>> bikes;
  bool isVisitBikes[11] = {
      false,
  };

  int answer = INT_MAX;
  int getDistance(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

  void recursive(int i, int cost) {
    if (i == workers.size()) {
      answer = min(answer, cost);
      return;
    }

    if (cost >= answer) return;

    for (int j = 0; j < bikes.size(); j++) {
      if (isVisitBikes[j]) continue;
      isVisitBikes[j] = true;

      int nextCost = cost + getDistance(workers[i], bikes[j]);
      recursive(i + 1, nextCost);

      isVisitBikes[j] = false;
    }
  }

 public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    this->workers = workers;
    this->bikes = bikes;

    recursive(0, 0);

    return answer;
  }
};

// use dynamic programming (bottom up) with bitmask
// time : O(N * 2^M)
// space : O(2^M)
class Solution {
 private:
  int memo[1024];

  // Count the number of ones using Brian Kernighan’s Algorithm
  int countNumOfOnes(int mask) {
    int count = 0;
    while (mask != 0) {
      mask &= (mask - 1);
      count++;
    }
    return count;
  }

  // Manhattan distance
  int findDistance(vector<int>& worker, vector<int>& bike) {
    return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
  }

 public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    for (int i = 0; i < 1024; i++) {
      memo[i] = INT_MAX;
    }
    int bikeSize = bikes.size();
    int workerSize = workers.size();
    int answer = INT_MAX;

    memo[0] = 0;
    for (int mask = 0; mask < (1 << bikeSize); mask++) {
      int workerI = countNumOfOnes(mask);

      if (workerI >= workerSize) {
        answer = min(answer, memo[mask]);
        continue;
      }

      for (int bikeI = 0; bikeI < bikeSize; bikeI++) {
        if ((mask & (1 << bikeI)) != 0) continue;
        int newMask = (1 << bikeI) | mask;

        int nextCost =
            memo[mask] + findDistance(workers[workerI], bikes[bikeI]);
        memo[newMask] = min(memo[newMask], nextCost);
      }
    }

    return answer;
  }
};