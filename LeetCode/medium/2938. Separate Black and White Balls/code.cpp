#include <algorithm>
#include <climits>
#include <cmath>
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

// use two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long minimumSteps(string s) {
    int size = s.size();

    int wI = size - 1, bI = size - 1;

    long long answer = 0;
    while (bI > 0 && wI > 0) {
      while (wI > 0 && s[wI] != '0') {
        wI--;
      }
      while ((wI < bI) || (bI >= 0 && s[bI] != '1')) {
        bI--;
      }
      if (bI == -1) break;

      swap(s[wI], s[bI]);
      answer += (wI - bI);
    }

    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long minimumSteps(string s) {
    int size = s.size();

    long long answer = 0;
    int blackBallCount = 0;
    for (char &c : s) {
      if (c == '0') {
        answer += blackBallCount;
      } else {
        blackBallCount++;
      }
    }

    return answer;
  }
};