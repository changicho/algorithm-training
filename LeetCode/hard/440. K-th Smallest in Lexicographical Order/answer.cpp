#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix search
// time : O(log_10(N)^2)
// space : O(1)
class Solution {
 public:
  int findKthNumber(int n, int k) {
    int result = 1;

    while (k > 1) {
      long count = 0, left = result, right = result + 1;
      while (left <= n) {
        count += min((long)n + 1, right) - left;

        left *= 10;
        right *= 10;
      }

      if (k > count) {
        k -= count;
        result++;
      } else {
        k--;
        result *= 10;
      }
    }
    return result;
  }
};