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

// use iteration
// time : O(log_3(N))
// space : O(1)
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;

    for (long long cur = 1; cur <= INT_MAX; cur *= 3) {
      if (cur == n) return true;
    }
    return false;
  }
};

// use iteration
// time : O(log_3(N))
// space : O(1)
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;

    while (n % 3 == 0) {
      n /= 3;
    }

    return n == 1;
  }
};