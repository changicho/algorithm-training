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

// use brute force
// time : O(N * log_10(N))
// space : O(1)
class Solution {
 private:
  bool hasZero(int num) {
    while (num > 0) {
      if (num % 10 == 0) {
        return true;
      }
      num /= 10;
    }
    return false;
  }

 public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n / 2; i++) {
      int a = i, b = n - i;

      if (!hasZero(a) && !hasZero(b)) {
        return {a, b};
      }
    }

    return {-1, -1};
  }
};