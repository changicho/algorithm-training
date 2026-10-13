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

// simulation
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  bool threeFibonacciSum(int n) {
    int a = 0, b = 1, c = 1;

    int sum = a + b + c;

    while (sum < n) {
      a = b;
      b = c;
      c = a + b;

      sum = a + b + c;
    }
    return sum == n;
  }
};

// math
// time : O(1)
// space : O(1)
class Solution {
 private:
  bool isSquare(long long x) {
    long long r = llround(sqrt((double)x));
    return r * r == x;
  }

 public:
  bool threeFibonacciSum(int n) {
    if (n % 2) return false;

    long long c = n / 2;

    return isSquare(5 * c * c + 4) || isSquare(5 * c * c - 4);
  }
};