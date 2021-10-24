#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search

class Solution {
 private:
  double estimateHour(vector<int>& dist, int speed) {
    double hour = 0;
    int size = dist.size();

    for (int i = 0; i < size - 1; i++) {
      int d = dist[i];
      hour += ceil((double)d / (double)speed);
    }

    hour += (double)dist.back() / (double)speed;

    return hour;
  }

 public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int size = dist.size();
    // impossible case
    if (hour + 1 < size) return -1;

    int left = 0, right = 10000000;

    int answer = INT_MAX;
    // use binary search
    while (left <= right) {
      int mid = left + (right - left) / 2;

      double estimate = estimateHour(dist, mid);
      if (estimate <= hour) {
        // pick left part
        right = mid - 1;
        answer = min(answer, mid);
      } else {
        // pick right part
        left = mid + 1;
      }
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};