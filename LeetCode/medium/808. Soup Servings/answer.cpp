#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(1)
// space : O(1)
class Solution {
 private:
  double memo[200][200];

  double recursive(int a, int b) {
    if (a <= 0 && b <= 0) return 0.5;
    if (a <= 0) return 1;
    if (b <= 0) return 0;

    if (memo[a][b] > 0) return memo[a][b];

    memo[a][b] = (recursive(a - 4, b) + recursive(a - 3, b - 1) +
                  recursive(a - 2, b - 2) + recursive(a - 1, b - 3)) /
                 4.0;

    return memo[a][b];
  }

  // when n = 4800, the result = 0.999994994426
  // so return 1 instead
 public:
  double soupServings(int n) {
    if (n >= 4800) return 1;

    int m = ceil(n / 25.0);

    return recursive(m, m);
  }
};