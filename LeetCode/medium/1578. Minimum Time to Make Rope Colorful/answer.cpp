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
  int minCost(string colors, vector<int>& neededTime) {
    int size = colors.size();

    char beforeC = colors[0];
    int beforeT = neededTime[0];

    int answer = 0;
    for (int i = 1; i < size; i++) {
      char c = colors[i];
      int time = neededTime[i];

      if (beforeC != c) {
        beforeC = c;
        beforeT = time;
        continue;
      }

      if (beforeT < time) {
        answer += beforeT;
        beforeT = time;
      } else {
        answer += time;
      }
    }

    return answer;
  }
};