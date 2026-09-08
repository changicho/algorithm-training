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

// custom pow
// time : O(N * (log_2(M) + log_10(M)))
// space : O(log_2(M))
class Solution {
 private:
  const int MOD = 1e9 + 7;

  long long myPow(long long x, long long y) {
    if (y == 0) return 1LL;
    if (y == 1) return x;
    long long ret = 1;

    if (y % 2 == 1) {
      ret *= x;
      y--;
    }

    long long half = myPow(x, y / 2);

    ret *= half;
    ret %= MOD;
    ret *= half;
    ret %= MOD;

    return ret;
  }

 public:
  int sumDecoded(vector<long long>& nums) {
    long long answer = 0;

    for (long long& num : nums) {
      long long w = num % 10;
      long long d = num / 10;

      long long digit = pow(10, (int)log10(d) - (w - 1));

      long long x = d / digit;
      long long y = d % digit;

      answer += myPow(x, y);
      answer %= MOD;
    }

    return answer;
  }
};