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

// use divide and conquer
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 private:
  const int MOD = 1e9 + 7;

  int myPow(int a, long long b) {
    // a^b;
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b == 2) return (a * a) % MOD;

    long long half = myPow(a, b / 2);
    long long ret = half * half;
    ret %= MOD;
    if (b % 2 == 1) ret *= a;
    ret %= MOD;
    return ret;
  }

 public:
  int countGoodNumbers(long long n) {
    int even = 5, odd = 4;

    long long evenCount = (n / 2) + n % 2, oddCount = n / 2;

    // 5^evenCount * 4^oddCount;
    long long answer = 1;
    if (evenCount > 0) {
      answer *= myPow(5, evenCount);
      answer %= MOD;
    }
    if (oddCount > 0) {
      answer *= myPow(4, oddCount);
      answer %= MOD;
    }
    return answer;
  }
};

// use divide and conquer (iterative)
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 private:
  const int MOD = 1e9 + 7;

  int myPow(int a, long long b) {
    int ret = 1, mul = a;
    while (b > 0) {
      if (b % 2 == 1) {
        ret = (long long)ret * mul % MOD;
      }
      mul = (long long)mul * mul % MOD;
      b /= 2;
    }
    return ret;
  }

 public:
  int countGoodNumbers(long long n) {
    int even = 5, odd = 4;

    long long evenCount = (n / 2) + n % 2, oddCount = n / 2;

    long long answer = 1;
    answer *= myPow(5, evenCount);
    answer %= MOD;

    answer *= myPow(4, oddCount);
    answer %= MOD;

    return answer;
  }
};