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

// use count
// time : O(log_10(N))
// space : O(1)
class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    vector<int> count(10);
    while (n > 0) {
      count[n % 10]++;
      n /= 10;
    }

    for (int i = 0; i < 31; i++) {
      vector<int> curCount(10);
      int num = (1 << i);

      while (num > 0) {
        curCount[num % 10]++;
        num /= 10;
      }

      if (curCount == count) return true;
    }
    return false;
  }
};