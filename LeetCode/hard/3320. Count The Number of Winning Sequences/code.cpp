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

// use dynamic programming
// time : O(N^2)
// space : O(N^2)
class Solution {
 private:
  const int MOD = 1e9 + 7;

  vector<char> types = {'F', 'W', 'E'};

  int isBobWin(char &a, char &b) {
    if (a == b) return 0;
    if (a == 'W' && b == 'E') return +1;
    if (a == 'E' && b == 'F') return +1;
    if (a == 'F' && b == 'W') return +1;
    return -1;
  }

 public:
  int countWinningSequences(string s) {
    int size = s.size();

    const int MID = 1000;

    // [index][type][diff] = case
    int memo[1001][3][2001] = {
        0,
    };

    int half = (size + 1) / 2;

    int minimum = MID - half, maximum = MID;
    for (int type = 0; type <= 2; type++) {
      int curDiff = MID + isBobWin(s[0], types[type]);

      maximum = max(maximum, curDiff);

      memo[0][type][curDiff] = 1;
    }

    for (int i = 1; i < size; i++) {
      for (int type = 0; type <= 2; type++) {
        for (int before = 0; before <= 2; before++) {
          if (type == before) continue;

          int left = minimum, right = maximum;

          for (int beforeDiff = left; beforeDiff <= right; beforeDiff++) {
            int beforeCase = memo[i - 1][before][beforeDiff];
            if (beforeCase == 0) continue;

            int curDiff = beforeDiff + isBobWin(s[i], types[type]);

            maximum = max(maximum, curDiff);

            memo[i][type][curDiff] += beforeCase;
            memo[i][type][curDiff] %= MOD;
          }
        }
      }
    }
    int answer = 0;
    for (int type = 0; type <= 2; type++) {
      for (int diff = MID + 1; diff <= maximum; diff++) {
        answer += memo[size - 1][type][diff];
        answer %= MOD;
      }
    }

    return answer;
  }
};