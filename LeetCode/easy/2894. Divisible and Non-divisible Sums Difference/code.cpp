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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int differenceOfSums(int n, int m) {
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++) {
      if (i % m == 0) {
        num2 += i;
      } else {
        num1 += i;
      }
    }

    return num1 - num2;
  }
};

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int differenceOfSums(int n, int m) {
    int sum = (n + 1) * n / 2;

    int count = n / m;
    int limit = (n / m) * m;

    int num2 = count * (2 * m + (count - 1) * m) / 2;
    int num1 = sum - num2;

    return num1 - num2;
  }
};