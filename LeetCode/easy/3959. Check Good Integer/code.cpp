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

using ll = long long;

// brute force
// time : O(log_10(N))
// space : O(1)
class Solution {
 public:
  bool checkGoodInteger(int n) {
    long long a = 0, b = 0;

    while (n > 0) {
      int cur = n % 10;
      n /= 10;

      a += cur;
      b += cur * cur;

      if (b - a >= 50) return true;
    }

    return (b - a) >= 50;
  }
};