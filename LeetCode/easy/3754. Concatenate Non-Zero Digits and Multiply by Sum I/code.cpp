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

// brute force
// time : O(log_10(N))
// space : O(1)
class Solution {
 public:
  long long sumAndMultiply(int n) {
    long long answer = 0;

    int sum = 0;
    int remain = 0;
    int digit = 1;

    while (n > 0) {
      int cur = n % 10;
      sum += cur;
      n /= 10;

      if (cur > 0) {
        remain += cur * digit;
        digit *= 10;
      }
    }

    return 1LL * sum * remain;
  }
};