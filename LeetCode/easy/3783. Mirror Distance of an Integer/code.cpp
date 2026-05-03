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

// math
// time : O(log_10(N))
// space : O(1)
class Solution {
 public:
  int mirrorDistance(int n) {
    int origin = n;
    int r = 0;
    while (n > 0) {
      r = r * 10 + n % 10;
      n /= 10;
    }

    return abs(origin - r);
  }
};