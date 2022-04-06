#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 private:
  bool isPossible(vector<int> &time, long long cur, long long totalTrips) {
    long long count = 0;
    for (int &t : time) {
      count += (long long)cur / t;

      if (count >= totalTrips) return true;
    }

    return false;
  }

 public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    long long answer = -1;
    long long left = 0, right = (long long)time.front() * totalTrips + 1;

    while (left < right) {
      long long mid = left + (right - left) / 2;

      if (isPossible(time, mid, totalTrips)) {
        answer = mid;
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return answer;
  }
};