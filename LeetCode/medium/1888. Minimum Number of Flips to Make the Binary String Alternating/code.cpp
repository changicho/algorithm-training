#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// prefix suffix
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minFlips(string s) {
    int size = s.size();

    int fromLeft = 0;
    for (int i = 0; i < size; i++) {
      char target = (i % 2 + '0');
      if (target != s[i]) {
        fromLeft++;
      }
    }

    int answer = min(fromLeft, size - fromLeft);

    if (size % 2 == 1) {
      int fromRight = 0;
      for (int i = size - 1; i >= 0; i--) {
        char target = (i % 2 + '0');
        if (target != s[i]) {
          fromRight++;
          fromLeft--;
        }

        answer = min(fromRight + (i - fromLeft), answer);
        answer = min(size - (fromRight + (i - fromLeft)), answer);
      }
    }

    return answer;
  }
};