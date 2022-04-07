#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(1)
// space : O(1)
class Solution {
 private:
  int convert(string time) {
    int minutes = ((time[0] - '0') * 10 + time[1] - '0') * 60 +
                  (time[3] - '0') * 10 + time[4] - '0';
    return minutes;
  }

 public:
  int convertTime(string current, string correct) {
    int curTime = convert(current), corTime = convert(correct);

    int step = 0;
    while (curTime < corTime) {
      if (curTime + 60 <= corTime) {
        curTime += 60;
      } else if (curTime + 15 <= corTime) {
        curTime += 15;
      } else if (curTime + 5 <= corTime) {
        curTime += 5;
      } else {
        curTime += 1;
      }

      step++;
    }

    return step;
  }
};

// use greedy (refactor)
// time : O(1)
// space : O(1)
class Solution {
 private:
  int convert(string time) {
    int minutes = ((time[0] - '0') * 10 + time[1] - '0') * 60 +
                  (time[3] - '0') * 10 + time[4] - '0';
    return minutes;
  }

 public:
  int convertTime(string current, string correct) {
    int curTime = convert(current), corTime = convert(correct);

    vector<int> times = {60, 15, 5, 1};

    int step = 0;
    for (int &time : times) {
      while (curTime + time <= corTime) {
        step++;
        curTime += time;
      }
    }

    return step;
  }
};