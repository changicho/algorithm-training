#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use priority queue

class Solution {
 public:
  int scheduleCourse(vector<vector<int>> &courses) {
    int size = courses.size();

    priority_queue<int> pq;  // duration max heap
    sort(courses.begin(), courses.end(),
         [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int day = 0;
    for (vector<int> &cur : courses) {
      int duration = cur[0], lastDay = cur[1];

      if (lastDay >= day + duration) {
        day += duration;
        pq.push(duration);
        continue;
      }
      // find most big duration before we took
      // because if we erase that, we can take current
      if (!pq.empty() && pq.top() > duration) {
        day -= pq.top();
        pq.pop();
        day += duration;
        pq.push(duration);
      }
    }

    return pq.size();
  }
};

// use dynamic programming top-down (TLE)

class Solution {
 private:
  struct Course {
    int duration, lastDay;

    bool operator<(const Course &b) const { return lastDay < b.lastDay; }
  };

  // dp[index][time] : is the maximum number of course can be take
  vector<vector<int>> dp;

  int recursive(vector<Course> &array, int index, int time) {
    if (index == array.size()) return 0;
    if (dp[index][time] != -1) {
      return dp[index][time];
    }

    int selectCase = 0;
    if (time + array[index].duration <= array[index].lastDay) {
      int nextTime = time + array[index].duration;
      selectCase = 1 + recursive(array, index + 1, nextTime);
    }
    int skipCase = recursive(array, index + 1, time);

    return dp[index][time] = max(selectCase, skipCase);
  }

 public:
  int scheduleCourse(vector<vector<int>> &courses) {
    int size = courses.size();

    vector<Course> array;
    for (vector<int> &course : courses) {
      array.push_back({course[0], course[1]});
    }
    sort(array.begin(), array.end());

    dp.resize(size, vector<int>(array.back().lastDay + 1, -1));

    return recursive(array, 0, 0);
  }
};

// use dynamic programming bottom-up (TLE)

class Solution {
 private:
  struct Course {
    int duration, lastDay;

    bool operator<(const Course &b) const { return lastDay < b.lastDay; }
  };

 public:
  int scheduleCourse(vector<vector<int>> &courses) {
    int size = courses.size();

    vector<Course> array;
    for (vector<int> &course : courses) {
      array.push_back({course[0], course[1]});
    }
    sort(array.begin(), array.end());
    // dp[index][time] : is the maximum number of course can be take
    vector<vector<int>> dp(size + 1, vector<int>(array.back().lastDay + 1, 0));

    for (int c = 1; c <= size; c++) {
      for (int d = 1; d <= array.back().lastDay; d++) {
        dp[c][d] = max(dp[c - 1][d], dp[c][d - 1]);

        if (d >= array[c - 1].duration && d <= array[c - 1].lastDay) {
          dp[c][d] = max(dp[c][d], 1 + dp[c - 1][d - array[c - 1].duration]);
        }
      }
    }

    return dp[size][array.back().lastDay];
  }
};