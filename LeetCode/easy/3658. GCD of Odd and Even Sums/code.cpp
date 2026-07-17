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
// time : O(N + log_2(N))
// space : O(1)
class Solution {
 public:
  int gcdOfOddEvenSums(int n) {
    int odd = 0, even = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (i % 2 == 0) {
        even += i;
      } else {
        odd += i;
      }
    }

    return gcd(odd, even);
  }
};

// math
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int gcdOfOddEvenSums(int n) {
    int odd = n * (2 + (n - 1) * 2) / 2;
    int even = n * (4 + (n - 1) * 2) / 2;

    return gcd(odd, even);
  }
};