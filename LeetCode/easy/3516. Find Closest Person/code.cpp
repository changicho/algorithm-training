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

// use diff
// time : O(1)
// space : O(1)
class Solution {
 public:
  int findClosest(int x, int y, int z) {
    int diffX = abs(z - x);
    int diffY = abs(z - y);

    if (diffX < diffY) {
      return 1;
    } else if (diffX > diffY) {
      return 2;
    } else {
      return 0;
    }
  }
};