#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int answer = 0;
    int endTime = -1;
    for (int& time : timeSeries) {
      if (time <= endTime) {
        answer -= abs(endTime + 1 - time);
      }

      answer += duration;
      endTime = time + duration - 1;
    }

    return answer;
  }
};