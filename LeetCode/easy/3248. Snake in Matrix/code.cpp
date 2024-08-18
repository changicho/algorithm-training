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

// use simulation
// time : O(M)
// space : O(1)
class Solution {
 public:
  int finalPositionOfSnake(int n, vector<string>& commands) {
    int cur = 0;

    for (string& c : commands) {
      if (c == "UP") {
        cur -= n;
      } else if (c == "RIGHT") {
        cur += 1;
      } else if (c == "DOWN") {
        cur += n;
      } else if (c == "LEFT") {
        cur -= 1;
      }
    }

    return cur;
  }
};