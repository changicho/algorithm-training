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

// count & greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  int furthestDistanceFromOrigin(string moves) {
    int size = moves.size();

    int dir = -1;
    int answer = 0;

    int leftCount = 0, rightCount = 0;
    int blankCount = 0;
    for (char& c : moves) {
      if (c == 'L') {
        leftCount++;
      } else if (c == 'R') {
        rightCount++;
      } else {
        blankCount++;
      }
    }

    int diff = abs(leftCount - rightCount);

    return diff + blankCount;
  }
};