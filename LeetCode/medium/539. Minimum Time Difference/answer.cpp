#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  int convert(string &time) {
    int hour = (time[0] - '0') * 10 + time[1] - '0';
    int minute = (time[3] - '0') * 10 + time[4] - '0';

    return hour * 60 + minute;
  }

 public:
  int findMinDifference(vector<string> &timePoints) {
    int size = timePoints.size();
    vector<int> nums;
    for (string &t : timePoints) {
      nums.push_back(convert(t));
    }

    sort(nums.begin(), nums.end());
    nums.push_back(nums[0] + 24 * 60);
    int answer = nums[1] - nums[0];
    for (int i = 0; i < size; i++) {
      int diff = nums[i + 1] - nums[i];

      answer = min(answer, diff);
    }
    return answer;
  }
};

// use counting sort
// time : O(N)
// space : O(1)
class Solution {
 private:
  int convert(string &time) {
    int hour = (time[0] - '0') * 10 + time[1] - '0';
    int minute = (time[3] - '0') * 10 + time[4] - '0';

    return hour * 60 + minute;
  }

 public:
  int findMinDifference(vector<string> &timePoints) {
    int size = timePoints.size();

    int counts[24 * 60] = {
        0,
    };

    int maximum = INT_MIN;
    for (string &t : timePoints) {
      int time = convert(t);

      counts[time]++;
      maximum = max(maximum, time);
      if (counts[time] >= 2) return 0;
    }

    int answer = INT_MAX;
    int before = maximum - 24 * 60;
    for (int time = 0; time < 24 * 60; time++) {
      if (counts[time] == 0) continue;

      int diff = time - before;

      answer = min(diff, answer);
      before = time;
    }

    return answer;
  }
};