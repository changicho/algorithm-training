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

// brute force
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    bool before = n % 2;
    n /= 2;

    while (n > 0) {
      bool cur = n % 2;
      n /= 2;

      if (before == cur) return false;
      before = cur;
    }
    return true;
  }
};