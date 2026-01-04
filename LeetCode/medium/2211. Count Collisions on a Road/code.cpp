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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countCollisions(string directions) {
    int rCount = 0;
    int sCount = 0;

    int answer = 0;
    for (char& c : directions) {
      if (c == 'L') {
        answer += rCount;
        if (sCount > 0 || rCount > 0) {
          answer += 1;
          sCount = 1;
        }
        rCount = 0;
      } else if (c == 'S') {
        answer += rCount;
        sCount = 1;
        rCount = 0;
      } else if (c == 'R') {
        rCount++;
      }
    }

    return answer;
  }
};